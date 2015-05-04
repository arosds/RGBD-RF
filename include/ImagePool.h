#ifndef RBGD_RF_IMAGEPOOL_HH__
#define RBGD_RF_IMAGEPOOL_HH__

#include <string>
#include <Image.h>
#include <PixelInfo.h>
#include <rdf/common.h>

namespace rdf {

/** \brief Container for the training images.
 */
class ImagePool { 
    public:
        ImagePool(const std::string imgDir);

        /** \brief Default destructor **/
        virtual ~ImagePool() {}

        /** \brief Reorder the pool given a array of index.
         *  \param[in] index_vector The vector with the indices
         */
        void poolReorder(std::vector<int>& index_vector);

        /** \brief Returns the number of images in the pool. */
        inline int poolSize() { return static_cast<int>(images.size()); }

        /** \brief this functions retrieves the pixel Label of an image given a
         *  PixelInfo object.
         *
         *  \param[in] pi The pixel identification.
         *  \return return The pixel label.
         */
        Label getLabel(const PixelInfo& pi);

        /** \brief this functions retrieves the pixel depth of an image given a
         *  PixelInfo object.
         *
         *  \param[in] pi The pixel identification.
         *  @return The pixel depth.
         */
        unsigned getDepth(const PixelInfo& pi);

        TrainImage* getImgPtr(unsigned i);

        TrainImage& operator[] (int i) { return images[i]; }

    private:
        std::vector<TrainImage> images;
};

} // namespace rdf

# endif // RGBD_RF_IMAGEPOOL_HH__
