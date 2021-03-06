//! \file
//! \author Shujian Yang
//!
//! Header file of class FilesystemTree.

#ifndef FILE_TREE_H
#define FILE_TREE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <functional>
#include <tsk/libtsk.h>
#include "../Basics/Basics.h"
#include "DirContent.h"

namespace btrForensics {
    class TreeExaminer;

    //! Analyze the file system tree in btrfs.
    class FilesystemTree {
    public:
        const BtrfsNode *fileTreeRoot; //!< Root node of the filesystem tree.
        uint64_t rootDirId; //!< Inode number of root directory.

    private:
        const TreeExaminer* examiner;

    public:
        FilesystemTree(const BtrfsNode*, uint64_t rootItemId, const TreeExaminer*);
        ~FilesystemTree();

        const void listDirItems(std::ostream& os) const;
        const void listDirItemsById(uint64_t id, bool dirFlag, bool fileFlag,
            bool recursive, int level, std::ostream& os) const;

        DirContent* getDirContent(uint64_t id) const;

        const void explorFiles(std::ostream& os, std::istream& is) const;
        
        const bool readFile(uint64_t id) const;
        const bool showInodeInfo(uint64_t id, std::ostream& os) const;
    };
}

#endif
