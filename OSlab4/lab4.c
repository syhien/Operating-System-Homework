asmlinkage long sys_filesys(char __user *file) {
    int ret = 0;
	loff_t pos = 0;

    struct inode *inode;
    struct file *filePointer;
    struct address_space *mapping;
    int blocks;
    int size;
    int blockCount;
    int i;

    filePointer = filp_open(file, O_RDONLY, 0);
    if (IS_ERR(filePointer)) {
		printk("is err\n");
		ret = PTR_ERR(filePointer);
	}
    else {
        inode = fp->f_path.dentry->d_inode;
        blocks = inode->i_blocks;
        size = inode->i_size;
        blockCount = (size + (3 << inode->i_blkbits) - 1) / inode->i_bytes;
        printk("%s\n", file);
        mapping = filePointer->f_mapping;
        for(i = 0; i < blockCount; i++) {
            printk("%d %d\n", i, mapping->a_ops->bmap(mapping, i));
        }
        filp_close(filePointer, NULL);
    }
    
    return ret;
}