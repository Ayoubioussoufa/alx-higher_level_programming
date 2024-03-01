import os

source_dir = "/mnt/c/Users/Ayoub/Desktop/il/0x05-python-exceptions"
dest_dir = "/mnt/c/Users/Ayoub/Desktop/alx-higher_level_programming/0x05-python-exceptions"
first_line = "#!/usr/bin/python3"
# Ensure destination directory exists
os.makedirs(dest_dir, exist_ok=True)

# Iterate over directories and files in the source directory
for root, dirs, files in os.walk(source_dir):
    # Create corresponding directories in the destination directory
    for dirname in dirs:
        dest_subdir = os.path.join(dest_dir, os.path.relpath(os.path.join(root, dirname), source_dir))
        os.makedirs(dest_subdir, exist_ok=True)

    # Create empty files in the destination directory
    for filename in files:
        source_path = os.path.join(root, filename)
        dest_path = os.path.join(dest_dir, os.path.relpath(source_path, source_dir))
        with open(dest_path, 'w') as dest_file:
            dest_file.write(first_line + '\n')
