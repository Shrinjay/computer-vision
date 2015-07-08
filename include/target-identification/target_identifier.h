#ifndef TARGET_IDENTIFIER_H_INCLUDED
#define TARGET_IDENTIFIER_H_INCLUDED

/**
 * @file target_identifier.h
 *
 * @brief Module for identifying targets in Frames
 *
 * Module analyzes frames using OpenCV tools,
 * locates objects of interest and gathers information 
 * about the objects such as target colour, pixel area,
 * perimeter and shape.
 *
 * Frames that do not contain targets will be deleted
 * Otherwise, the responsibility for deleting Frames and the PixelTargets created
 * by the TargetIdentifier passes to whoever invokes popProcessed;
**/

#include "frame.h"

class TargetIdentifier{
    public:
        TargetIdentifier();

        ~TargetIdentifier();


        /**
         * @brief Puts the given Frame into the processing queue
         *
         * @param f Frame to be processed
         */
        void process_frame(Frame * f);

        /**
         * @brief retrieves a vector containing all of the frames that have
         *        been processed and now contain targets and removes them from
         *        from the TargetIdentifier's buffer
         *        The caller of the function is responsible for deleting the 
         *        frames
         *        Not all frames passed to the identifier will leave through
         *        popProcessed()
         *
         * @return vector containing tthe frames which have been processed 
         */
        vector<Frame *> pop_processed();
};


#endif // TARGET_IDENTIFIER_H_INCLUDED