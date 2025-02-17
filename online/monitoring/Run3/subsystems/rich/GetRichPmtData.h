/* The class GetRichPmtdata is used to read and decode PHENIX raw data format
 * from a specified file or a ddpool. The sequence of events is:
 *
 *       The calling program creates a new object of class GetRichPmtData.
 *
 *       The GetRichPmtData constructor opens the data source by creating a
 *       new event iterator, it.
 *
 *       The calling program starts a loop over data events, for each loop:
 *
 *         The calling program calls GetRichPmtData::get_next_event, which 
 *         gets a pointer (evt) to the next event from the data source.
 *        
 *         The calling program then loops over all 5,120 PMT channels, reading
 *         out 1 PMT channel at a time by repeatedly calling the function
 *         GetRichPmtData::get_pmt_data. (The get_pmt_data function 
 *         automatically creates new packet pointers when the data in each 
 *         packet are exhausted).
 *
 *         When all events have been read from the data source, the 
 *         get_next_event function returns 1.
 *
 *       Finally, the calling program deletes the GetRichPmtData object.
 *
 *  An example of the use of this class can be found on RichOnlineMonitor.C
 *
 */

#ifndef __GETRICHDATA__
#define __GETRICHDATA__

#include "RICHMonDefs.h"
#include "RichGeom.h"

class Event;
class Packet;

struct getpmtdata_err{
  int err_type;
  int pckt;
  int evt;
  int opt_info;
};


class GetRichPmtData {

  RichGeom *geo;
  Event *evt;
  Packet *p;

  int pnum;
  int packetsperevent;
  int chanperpack;
  int wordsperpacket;
  int print_hits;
  int Format;     // This is the Hit Format of the packet

  int ich;        // current channel number
  int ip;         // current packet number
  long run;
  int fem_id;

  int edate;
  int etime;

  float *pedestal;
  float *sigped;
  float *pep;
  float *sigpep;

  int packetdata[1000];

  int rawadcval[160];
  int rawadcpval[160];
  int rawadcpreval[160];
  int rawtacval[160];

  int nerr;
  struct getpmtdata_err pckt_err[160];

 public:

  GetRichPmtData(Event *event,int *stat,float *pedestal,float *sigped, float *pep,float *sigpep,int pr_hts);
  virtual ~GetRichPmtData();
  int get_all_data_at_once(int ip);
  int get_next_event();
  int get_next_packet(int fem_id);
  int get_pmt_data(int *pmtn,int *adcp,int *adcv,int *tacv,float *nh,int *sect
		   ,float *zed,float *ph);
  int get_run_number(long * runout);
  int get_date(int *dt,int *tm);
  int decode_data_1X06(int rawtac,int rawadcpre,int rawadcpost,int *tac,int *adcval,int *adcpost,int *ch_no,int *adcpre);
  int decode_data_406(int rawtac,int rawadcpre,int rawadcpost,int *tac,int *adcval,int *adcpost,int *ch_no,int *adcpre);
  int get_packetdata(int pos_dcmout){return packetdata[pos_dcmout] & 0xffff;};


  int get_err_num(){return nerr;};   // returns N of errors
  struct getpmtdata_err get_err(int err_id){return pckt_err[err_id];};

  /*
    Error Type List (err_type) and the meaning of option (opt_info)
     1: Trailer data Error     Opt: N of Errors
     2: Detector ID Error      Opt: Error Data
     3: Flag Word Error        Opt: Error Data
     4: Packet discarded       Opt: N of Format Errors

     8: Several Eight Serial "ffff"       Opt: N of Clusters
    16: So much Eight Serial "ffff"       Opt: N of clusters   
        (Either pre, post or tac > 3)
    32: Too much Serial "ffff"            Opt: N of Clusters
        (Total >20 or either pre, post or tac > 8)
  */
  

};

#endif /* __GETRICHDATA__ */



