# Kunal Agarwal MT2024083
#1. Create the following types of a files using shell command
#a. soft link (symlink system call)
#b. hard link (link system call)
#c. FIFO (mkfifo Library Function or mknod system call)*/
# Create a symbolic link
ln -s "hi.txt" "soft_link_name"
echo "Symbolic link 'soft_link_name' created."

# Create a hard link
ln "hi.txt" "hard_link_name"
echo "Hard link 'hard_link_name' created."

# Create a FIFO (named pipe)
mkfifo "fifo_name"
echo "FIFO 'fifo_name' created."