#include <TrainData.h>

rdf::TrainData::TrainData() {
    pixelC = std::vector<PixelInfo>();
}

/**
 * Creates an empty vector of trainImgNum x numPixels
 */
 //CHECK
rdf::TrainData :: TrainData (int trainImgNum, int numPixels) {
    pixelC = std::vector<PixelInfo>(trainImgNum * numPixels);
}

/** \brief Constructor.
 *
 *  Sample random points from the range specified of images in the pool.
 *
 *  \param[in] numPixels Number of pixels to sample.
 *  \param[in] startIdx Index from the Impage Pool.
 *  \param[in] endIdx 
 *  \param[in] byLabel  
 */
rdf::TrainData::TrainData(
    int numPixels,
    ImagePool& imgPool,
    int startIdx,
    int endIdx,
    bool byLabel) {

    int j;
    int imgIdx;
    uint32_t row;
    uint32_t col;
    vector <PixelInfo> pix;
    
    // iterates through image pool and get numImg subset of
    // them, then takes numPixels from the current image
    for (imgIdx = startIdx; imgIdx <= endIdx; imgIdx++) {

        if (byLabel == true) {
            imgPool[imgIdx].getRandCoordByLabel(numPixels, pix, imgIdx);
            pixelC.insert(pixelC.end(), pix.begin(), pix.end());

        } else {
            for (j = 0; j < numPixels; j++) {

                imgPool[imgIdx].getRandomCoord(row, col);
                pixelC.push_back(PixelInfo(row, col, imgIdx));

            }
        }
    }
}

/** \brief Returns the number of pixels
 *  \return The number of pixels.
 */
int rdf::TrainData::size() {
    return static_cast<int>(pixelC.size());
}
