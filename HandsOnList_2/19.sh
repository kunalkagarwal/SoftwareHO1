# a. Create a FIFO using mknod
mknod my_fifo_mknod p && echo "mknod: FIFO created."

# b. Create a FIFO using mkfifo
mkfifo my_fifo_mkfifo && echo "mkfifo: FIFO created."

# c. Compare with strace
echo "strace for mknod:" && strace -c mknod trace_fifo_mknod p
echo "strace for mkfifo:" && strace -c mkfifo trace_fifo_mkfifo

# Cleanup
rm -f my_fifo_mknod my_fifo_mkfifo trace_fifo_mknod trace_fifo_mkfifo