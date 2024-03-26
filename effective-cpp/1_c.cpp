class FileSystem {..};
FileSystem& tfs()
{
    static FileSystem fs;
    return fs;
}

class Directory{...};
Directory::Directory(params)
{
    std::size_t disks tfs().numDisks();
}

Directory& tempDir()
{
    static Directory td(params);
    return td;
}
