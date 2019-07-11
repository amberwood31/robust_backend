//
// Created by amber on 09/07/19.
//

#ifndef RTABMAP_POSEVIEWER_H
#define RTABMAP_POSEVIEWER_H

#endif //RTABMAP_POSEVIEWER_H

#include "rtabmap/gui/RtabmapGuiExp.h" // DLL export/import defines

#include <QMainWindow>
#include <QtCore/QByteArray>
#include <QtCore/QMap>
#include <QtCore/QSet>
#include <QtGui/QImage>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <set>
#include <vector>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <rtabmap/core/Link.h>
#include <rtabmap/core/Signature.h>

class Ui_PoseViewer;
class QGraphicsScene;
class QGraphicsView;
class QLabel;
class QDialog;

namespace rtabmap
{
    class DBDriver;
    class ImageView;
    class SensorData;
    class CloudViewer;
    class OctoMap;
    class ExportCloudsDialog;
    class EditDepthArea;
    class EditMapArea;

    class RTABMAPGUI_EXP PoseViewer : public QMainWindow
    {
    Q_OBJECT

    public:
        PoseViewer(const QString & ini = QString(), QWidget * parent = 0);
        virtual ~PoseViewer();
        bool openDatabase(const QString & path);
        bool isSavedMaximized() const {return savedMaximized_;}
        void showCloseButton(bool visible = true);

    protected:
        virtual void showEvent(QShowEvent* anEvent);
        virtual void moveEvent(QMoveEvent* anEvent);
        virtual void resizeEvent(QResizeEvent* anEvent);
        virtual void keyPressEvent(QKeyEvent *event);
        virtual void closeEvent(QCloseEvent* event);
        virtual bool eventFilter(QObject *obj, QEvent *event);

    private Q_SLOTS:
        void writeSettings();
        void restoreDefaultSettings();
        void configModified();
        void openDatabase();
        bool closeDatabase();
        void recoverDatabase();
        void updateInfo();
        void updateStatistics();
        void selectObstacleColor();
        void selectGroundColor();
        void selectEmptyColor();
        void editDepthImage();
        void generateGraph();
        void editSaved2DMap();
        void exportSaved2DMap();
        void import2DMap();
        void regenerateSavedMap();
        void viewOptimizedMesh();
        void exportOptimizedMesh();
        void updateOptimizedMesh();
        void exportDatabase();
        void extractImages();
        void exportPosesRaw();
        void exportPosesRGBDSLAMMotionCapture();
        void exportPosesRGBDSLAM();
        void exportPosesKITTI();
        void exportPosesTORO();
        void exportPosesG2O();
        void exportPosesKML();
        void exportGPS_TXT();
        void exportGPS_KML();
        void generateLocalGraph();
        void regenerateLocalMaps();
        void regenerateCurrentLocalMaps();
        void view3DMap();
        void generate3DMap();
        void detectMoreLoopClosures();
        void updateAllNeighborCovariances();
        void updateAllLoopClosureCovariances();
        void refineAllNeighborLinks();
        void refineAllLoopClosureLinks();
        void resetAllChanges();
        void sliderAValueChanged(int);
        void sliderBValueChanged(int);
        void sliderAMoved(int);
        void sliderBMoved(int);
        void update3dView();
        void sliderNeighborValueChanged(int);
        void sliderLoopValueChanged(int);
        void sliderIterationsValueChanged(int);
        void updateGrid();
        void updateOctomapView();
        void updateGraphView();
        void refineConstraint();
        void addConstraint();
        void resetConstraint();
        void rejectConstraint();
        void updateConstraintView();
        void updateLoggerLevel();
        void updateStereo();
        void notifyParametersChanged(const QStringList &);
        void setupMainLayout(bool vertical);

    private:
        QString getIniFilePath() const;
        void readSettings();

        void updateIds();
        void update(int value,
                    QLabel * labelIndex,
                    QLabel * labelParents,
                    QLabel * labelChildren,
                    QLabel * weight,
                    QLabel * label,
                    QLabel * stamp,
                    rtabmap::ImageView * view,
                    QLabel * labelId,
                    QLabel * labelMapId,
                    QLabel * labelPose,
                    QLabel * labelVelocity,
                    QLabel * labelCalib,
                    QLabel * labelScan,
                    QLabel * labelGps,
                    QLabel * labelSensors,
                    bool updateConstraintView);
        void updateStereo(const SensorData * data);
        void updateWordsMatching();
        void updateConstraintView(
            const rtabmap::Link & link,
            bool updateImageSliders = true,
            const Signature & signatureFrom = Signature(0),
            const Signature & signatureTo = Signature(0));
        void updateConstraintButtons();
        Link findActiveLink(int from, int to);
        bool containsLink(
            std::multimap<int, Link> & links,
            int from,
            int to);
        std::multimap<int, rtabmap::Link> updateLinksWithModifications(
            const std::multimap<int, rtabmap::Link> & edgeConstraints);
        void updateLoopClosuresSlider(int from = 0, int to = 0);
        void updateAllCovariances(const QList<Link> & links);
        void refineAllLinks(const QList<Link> & links);
        void refineConstraint(int from, int to,  bool silent);
        bool addConstraint(int from, int to, bool silent);
        void exportPoses(int format);
        void exportGPS(int format);

    private:
        Ui_DatabaseViewer * ui_;
        CloudViewer * constraintsViewer_;
        CloudViewer * cloudViewer_;
        CloudViewer * stereoViewer_;
        CloudViewer * occupancyGridViewer_;
        QList<int> ids_;
        std::set<int> lastWmIds_;
        std::map<int, int> mapIds_;
        std::map<int, int> weights_;
        std::map<int, std::vector<int> > wmStates_;
        QMap<int, int> idToIndex_;
        QList<rtabmap::Link> neighborLinks_;
        QList<rtabmap::Link> loopLinks_;
        int lastSliderIndexBrowsed_;
        rtabmap::DBDriver * dbDriver_;
        QString pathDatabase_;
        std::string databaseFileName_;
        std::list<std::map<int, rtabmap::Transform> > graphes_;
        std::multimap<int, rtabmap::Link> graphLinks_;
        std::map<int, rtabmap::Transform> odomPoses_;
        std::map<int, rtabmap::Transform> dbOptimizedPoses_;
        std::map<int, rtabmap::Transform> groundTruthPoses_;
        std::map<int, rtabmap::Transform> gpsPoses_;
        std::map<int, GPS> gpsValues_;
        std::multimap<int, rtabmap::Link> links_;
        std::multimap<int, rtabmap::Link> linksRefined_;
        std::multimap<int, rtabmap::Link> linksAdded_;
        std::multimap<int, rtabmap::Link> linksRemoved_;
        std::map<int, std::pair<std::pair<cv::Mat, cv::Mat>, cv::Mat> > localMaps_; // < <ground, obstacles>, empty>
        std::map<int, std::pair<float, cv::Point3f> > localMapsInfo_; // <cell size, viewpoint>
        std::map<int, std::pair<std::pair<cv::Mat, cv::Mat>, cv::Mat> > generatedLocalMaps_; // < <ground, obstacles>, empty>
        std::map<int, std::pair<float, cv::Point3f> > generatedLocalMapsInfo_; // <cell size, viewpoint>
        std::map<int, cv::Mat> modifiedDepthImages_;
        std::vector<double> odomMaxInf_;
        OctoMap * octomap_;
        ExportCloudsDialog * exportDialog_;
        QDialog * editDepthDialog_;
        EditDepthArea * editDepthArea_;
        QDialog * editMapDialog_;
        EditMapArea * editMapArea_;

        bool savedMaximized_;
        bool firstCall_;
        QString iniFilePath_;

        bool infoReducedGraph_;
        double infoTotalOdom_;
        double infoTotalTime_;
        int infoSessions_;

        bool useLastOptimizedGraphAsGuess_;
        std::map<int, Transform> lastOptimizedGraph_;
    };






}