

#ifndef __PHOTONS_H__
#define __PHOTONS_H__


#include <fun4all/SubsysReco.h>
#include <vector>

#include <TTree.h>
#include <TMath.h>
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>

class PHCompositeNode;
class RawClusterContainer;
class RawCluster;
class SvtxTrackMap;
class JetMap;
class JetEvalStack;
class JetRecoEval;
class SvtxTrackEval;
class PHG4TruthInfoContainer;
class PHHepMCGenEvent;
class Photons: public SubsysReco
{

 public:
  
  Photons(const std::string &name="photonjet.root");
  double isoconeradius,mincluspt;
  float jet_cone_size;
  float _etalow, _etahi;
  int use_isocone;
  int Init(PHCompositeNode*);
  int process_event(PHCompositeNode*);
  int End(PHCompositeNode*);
 
  void set_cluspt_mincut(double pt){mincluspt = pt;};
  void SetFirstEventNum(int eventnum){nevents=eventnum;};
  void set_eta_lowhigh(float etalow, float etahi){_etalow=etalow; _etahi=etahi;};



private:

  void Set_Tree_Branches();
 

  TFile *file;
  TTree *tree;
  TTree *cluster_tree;
  TTree *truth_g4particles;
  TTree *inhcal_tree;
  TTree *fcluster_tree;
 
  std::string outfilename;

  int nevents;
  TH1F *histo;

  //hcalcluster info
  float hcal_energy;
  float hcal_eta;
  float hcal_phi;
  float hcal_pt;
  float hcal_px;
  float hcal_py;
  float hcal_pz;
  float hcal_theta;
  float hcal_x, hcal_y, hcal_z, hcal_t;


  //cluster info
  float clus_energy;
  float clus_eta;
  float clus_phi;
  float clus_pt;
  float clus_px;
  float clus_py;
  float clus_pz;
  float clus_theta;
  float clus_x,clus_y,clus_z,clus_t;



  //all truth particles
  float truthpx,truthpy,truthpz;
  float truthp;
  float truthphi;
  float trutheta;
  float truthpt;
  float truthenergy;
  int truthpid;
  int numparticlesinevent;
  int process_id;


  //clust truth variables
  float clustruthpx;
  float clustruthpy;
  float clustruthpz;
  float clustruthenergy;
  float clustruthpt;
  float clustruthphi;
  float clustrutheta;
  int clustruthpid;
  float hclustruthpx;
  float hclustruthpy;
  float hclustruthpz;
  float hclustruthenergy;
  float hclustruthpt;
  float hclustruthphi;
  float hclustrutheta;
  int hclustruthpid;



  //forward clusters
  float fclusenergy;
  float fclus_eta;
  float fclus_phi;
  float fclus_theta;
  float fclus_pt;
  int fclustruthpid;
  float fclustruthpx;
  float fclustruthpy;
  float fclustruthpz;
  float fclustruthenergy;
  float fclustruthpt;
  float fclustruthphi;
  float fclustrutheta;
  float fclus_px;
  float fclus_py;
  float fclus_pz;


  const float pi2 = -1.5707963;
  const float threepi2 = 4.71238898;
  const float pi = 3.1415926;

};

#endif // __PHOTONS_H__
