#ifndef FEATURESET_H
#define FEATURESET_H


#include <opencv2/opencv.hpp>

#include <fingertipSet.h>

#include <cameraSet.h>


//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////


union PCD_RGB
{
    struct
    {
        uchar B; // LSB
        uchar G; // ---
        uchar R; // MSB
        uchar A;
    };
    float RGB_float;
    uint  RGB_uint;
};


//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////


struct PCL_Point
{
    double  x;
    double  y;
    double  z;
    PCD_RGB rgb;
};


//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////


struct PointCloud
{
    QVector<QVector< PCL_Point> > points;
};


//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////


class FeatureSet
{
public:
    FeatureSet();

    QVector<PointCloud> PCL_Curr;

    FingertipSet fingerTips;

    void clear( int totalCameras );

    void BackProject_Depth_2_PCL( const int &camID, const QVector<double> &intrinsicsVec_fx_fy_cx_cy, const cv::Mat &Img_COL_RAWW_Curr, const cv::Mat &Img_DDD_RAWW_Curr );
};

#endif // FEATURESET_H
