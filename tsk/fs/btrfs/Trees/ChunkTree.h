//! \file
//! \author Shujian Yang
//!
//! Header file of class ChunkTree

#ifndef CHUNK_TREE_H
#define CHUNK_TREE_H

#include <iostream>
#include <string>
#include <vector>
#include <tsk/libtsk.h>
#include "../Basics/Basics.h"
#include "SuperBlock.h"

namespace btrForensics {
    class TreeExaminer;

    //! Process chunk tree of Btrfs.
    class ChunkTree {
    public:
        const BtrfsNode* chunkRoot; //!< Root of chunk tree.
    private:
        const TreeExaminer* examiner;

    public:
        ChunkTree(const SuperBlock* superBlk, const TreeExaminer* treeExaminer);
        ~ChunkTree();
        
        std::vector<BTRFSPhyAddr> getPhysicalAddr(uint64_t logicalAddr);
        uint64_t getChunkLogical(uint64_t logicalAddr);

    };

}

#endif
