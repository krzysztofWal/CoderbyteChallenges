"""depending on the variable settings inserts tags into source files and/or prints readme to the terminal"""

# should be run from ../
import pylightxl as xl
import re
import subprocess
import os
import sys
# comment/uncomments pdb import to disable/enable debug breakpoints
# import pdb

if __name__ == "__main__":

# ============================================= Variables =================================================
    source_dir = 'src'
    import_path = './tools/challenges_list.xlsx'
    worksheet_name = ('Sheet1')
    info_cell_adress = 'B1'
    tag_delimiter = ','
    gitignore_file = '.git/info/exclude'
    
    insert_tags_into_files = False
    generate_readme = True
    care_for_gitignore = True

    # set the debug flag
    if 'pdb' not in sys.modules:
        if_debugging = False
    else:
        if_debugging = True

    # if you want to print the readme file into the console
    if generate_readme:
        base_readme_text = '\n'.join(["### Coderbyte challenges",
        "This repository contains solutions to challenges from Coderbyte.",
        "",
        "Stated 'achieved complexity' was calculated with Coderbyte analysis tool (https://coderbyte.com/big-o-runtime-guide)",
        "",
        "### Sorted by tags"])
        
        base_link = r"https://github.com/krzysztofWal/CoderbyteChallenges/blob/master/"

# =========================================================================================================

    def get_ignored(filename : str) -> list:
        """Read the file line by line and return lines that are like
          'src/src_file_name\n' (does not return the \n character), 
          ignore if the number of subdirectories is larger than
          one and if the subdirectory is not src

        Args:
            filename (str) : name of the file to be read
        
        Returns:
            list: list of files in the drc catalogue to be ignored
        """
        git_list = []
        
        with open(filename,'r') as ignore:
            for ignore_file in ignore:
                full_path_split = ignore_file.removesuffix('\n').split('/');
                if len(full_path_split) == 2 and full_path_split[0] == 'src':

                    # if if_debugging: pdb.set_trace();

                    git_list.append(full_path_split[1])

        # if if_debugging: pdb.set_trace();
    
        return git_list

    def is_python(filename : str) -> bool:
        """Return 'True' if the file extension is '.py'.

        Args:
            filename (str): Name of the file. 
        """
        return True if filename.split('.')[-1] == 'py' else False

    def extract_range(adress_string: str) -> tuple:
        """Take the properly formatted string and extract information.

        Expects the input string to be in format 'aX-aY;b', where a and b
        are letters (colums) and X and Y are positive integers (rows)
        Args:
            adress_string (str): Formatted string.

        Returns:
            tuple: Tuple in form: (sorted list [x,y], a, b).
        """
        adress_string_disassembled = adress_string.split(';')
        # first and last row of files list
        nums = re.findall(r'\d+', adress_string_disassembled[0])
        # colum of files list
        adress_string_disassembled[0] = adress_string_disassembled[0].split(
            '-')
        letter = "".join(
            re.split(r'[^a-zA-Z]*', adress_string_disassembled[0][0]))
        # column with tags
        letter_tags = "".join(
            re.split(r'[^a-zA-Z]*', adress_string_disassembled[1]))
        # make nums a list of sorted integers
        nums = [int(i) for i in sorted(nums)]
        # nums shoud be 2 element list containing integers > 1
        # letter and letter_tags should be two different letters
        return nums, letter, letter_tags

    def filename_tags_iterator(db_obj, worksheet_name: str, nums: list,
                               letter: str, letter_tags: str):
        """Generate from defined range of cells filenames and tags.

        Range from which to read filenames is provided as a list containing 
        first and final rows and column letter ('letter'). The tags for each 
        filename are on the same row in column 'letter_tags'.
        Args:
            db_obj : Instance of pylightxl Database.
            worksheet_name (str): Name of the worksheet from which to read.
            nums (list): [x, y] where x is the starting row and y is the
                        final row from which to read filenames and tags.
            letter (str): Column from which to read filenames.
            letter_tags (str): Column from which to read tags.

        Yields:
            Iterator[tuple]: Tuple in form (filename, tags), where both
                            are strings.
        """
        it = nums[0]
        while it < nums[1] + 1:
            
            filename = db_obj.ws(ws=worksheet_name).address(letter+str(it));
            file_tags = db_obj.ws(ws=worksheet_name).address(letter_tags+str(it)).strip();

            # if if_debugging: pdb.set_trace();

            yield (filename, file_tags)
            
            it += 1

    def make_tagged_copy(filename: str, copy_name: str, formatted_tags: str):
        """Create a copy of the file with tags in int.

        Iterate over each line in the source file and insert 'formatted_tags'
        appropriate number of lines below the line on which the first comment block starts
        Args:
            filename (str): Source file to be copied.
            copy_name (str): Name of the copy of the file to be created.
            formatted_tags (str): Tags to be inserted into the copy.
        """
        def tags_are_present(line: str, is_python: bool):
            # check if the document is already tagged on this line
            # by counting occurences od '#'
            if is_python:
                return True if line.count('#') > 1 else False
            else:
                return True if line.count('#') > 0 else False
        
        def write_line(text_file_wrapper, cnt: int, comm_line_nr: int, line: str,
                offset: int, comment_start: str, formatted_tags: str, flag: bool):
            # if found the beginning of the first block comment, set the 'memory' value
            if comment_start in line and not flag:
                comm_line_nr = cnt
                flag = True
            # write tags into the appropriate line with right amount of newlines
            # that amount depends on whether some tags were already present in the files
            elif comm_line_nr != -1 and cnt == comm_line_nr + offset:
                # if tags are already in this file, do not add newlines after the tags
                file_is_python = is_python(text_file_wrapper.name)
                tags_are_not_present = not tags_are_present(line, file_is_python)
                if tags_are_not_present and file_is_python:
                    formatted_tags = ''.join(['# ', formatted_tags, '\n# \n'])
                elif tags_are_not_present and not file_is_python:
                    formatted_tags += '\n\n'
                elif not file_is_python:
                    formatted_tags += '\n'
                else:
                    formatted_tags = ''.join(['# ', formatted_tags, '\n'])

                text_file_wrapper.write(formatted_tags)
            # Write the 'non-tags' line into the copy file
            if comm_line_nr == -1 or cnt != comm_line_nr + offset:
                text_file_wrapper.write(line)
            return comm_line_nr, flag

        offset, comment_start = (1, '#') if is_python(filename) else (2, '/*')
        # open file from which to read and create a copy file to write into
        with open(filename, 'r') as source_file, open(copy_name, 'w') as copy_file:
            cnt = 1
            comm_line_nr = -1
            flag = False
            for line in source_file:
                comm_line_nr, flag = write_line(
                    copy_file, cnt, comm_line_nr, line,
                    offset, comment_start, formatted_tags, flag)
                cnt += 1

    def rename_file(second: str, first: str):
        """Rename the file 'first' to 'second' by copying
        
        Uses sytem 'copy' command, to copy file ./first to ./second.
        The result is two copies of ./first file one with the original
        name one called 'second'. If 'second' already exists it is
        overwritten
        Args:
            first (str): The original name of the file.
            second (str): The target name of the file.

        Returns:
            int: Returncode of 'copy' command.
        """
        command = ''.join(['copy /y "', os.getcwd(), '\\',first,
                           '" "', os.getcwd(), '\\', second, '"'])
        result = subprocess.run(command, shell=True, stdout=subprocess.DEVNULL)
        return result.returncode

    def delete_file(filename: str):
        """Delete the file 'filename'.

        Calls 'del' system command and deletes the file. 
        Note: The file should be in the same directory as this script
        Args:
            filename (str): name of the file to be deleted

        Returns:
            int: returncode from operation del. 0 if the deletion was succesfull.
        """
        command = ''.join(['del "', os.getcwd(), '\\', filename, '"'])
        result = subprocess.run(command, shell=True, stdout=subprocess.DEVNULL)
        return result.returncode

    # ignore files list
    # empty if the flag care_for_gitignore is set to false
    git_list = []
    if care_for_gitignore:
        git_list = get_ignored(gitignore_file)

    # read xls file and read adresses with relevant information
    db = xl.readxl(fn=import_path, ws=(worksheet_name))
    nums, letter, letter_tags = extract_range(db.ws(ws=worksheet_name).address(info_cell_adress))
    # create an empty hash map for the tags
    tag_dictionary = {}
    
    # get all filenames and associated tags
    for filename, tags in filename_tags_iterator(db, worksheet_name, nums, letter, letter_tags):
        
        # if if_debugging and filename in git_list: pdb.set_trace();

        if tags == '' or filename in git_list:
            # if there ane no tags associated with that file 
            # or the file is in git_list
            
            # if generate_readme and if_debugging: pdb.set_trace();

            if insert_tags_into_files:
                print("INFO: ", filename, "has no associated tags")
        else:
            if insert_tags_into_files:
                filename_with_src = ''.join(['/', source_dir, '/', filename])
                copy_name = str(filename_with_src).replace('.', '_copy.')
                # get string with tags to write as line in the source file
                formatted_tags = ''.join([''.join(['#', tag, ' '])
                                        for tag in tags.split(tag_delimiter)])
                # create a copy of the file with added tags
                make_tagged_copy(filename_with_src, copy_name, formatted_tags)
                # rename the copy as the original file
                if rename_file(copy_name, filename_with_src) != 0:
                    print("Error copying", copy_name, "into", filename_with_src)
                # delete the copy
                elif delete_file(copy_name) != 0:
                    print("Error deleting", copy_name)
                else:
                    print("Tags sucsesfully added/replaced in", filename_with_src)
        
            if generate_readme:

                # if if_debugging: pdb.set_trace();

                # add the filename to tag_dictionary
                for tag in tags.split(tag_delimiter):
                    filename_wrapped = ''.join(['[', filename, '](', base_link, 'src/' ,filename, ' "', 'Go to the source file', '")'])
                    if tag in tag_dictionary:
                        tag_dictionary[tag].append(filename_wrapped)
                    else:
                        tag_dictionary[tag] = [filename_wrapped]

    # print to terminal 
    if generate_readme:
        print(base_readme_text)
        for key in sorted(tag_dictionary): # return sorted list of keys
            print(f"- **\#{key}:** " + ', '.join(sorted(tag_dictionary[key])))        