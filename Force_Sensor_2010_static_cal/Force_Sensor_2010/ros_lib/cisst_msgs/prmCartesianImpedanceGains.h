#ifndef _ROS_cisst_msgs_prmCartesianImpedanceGains_h
#define _ROS_cisst_msgs_prmCartesianImpedanceGains_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Quaternion.h"
#include "geometry_msgs/Vector3.h"

namespace cisst_msgs
{

  class prmCartesianImpedanceGains : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Quaternion _ForceOrientation_type;
      _ForceOrientation_type ForceOrientation;
      typedef geometry_msgs::Vector3 _ForcePosition_type;
      _ForcePosition_type ForcePosition;
      typedef geometry_msgs::Quaternion _TorqueOrientation_type;
      _TorqueOrientation_type TorqueOrientation;
      typedef geometry_msgs::Vector3 _PosDeadbandPos_type;
      _PosDeadbandPos_type PosDeadbandPos;
      typedef geometry_msgs::Vector3 _PosDeadbandNeg_type;
      _PosDeadbandNeg_type PosDeadbandNeg;
      typedef geometry_msgs::Vector3 _PosStiffPos_type;
      _PosStiffPos_type PosStiffPos;
      typedef geometry_msgs::Vector3 _PosStiffNeg_type;
      _PosStiffNeg_type PosStiffNeg;
      typedef geometry_msgs::Vector3 _PosDampingPos_type;
      _PosDampingPos_type PosDampingPos;
      typedef geometry_msgs::Vector3 _PosDampingNeg_type;
      _PosDampingNeg_type PosDampingNeg;
      typedef geometry_msgs::Vector3 _ForceBiasPos_type;
      _ForceBiasPos_type ForceBiasPos;
      typedef geometry_msgs::Vector3 _ForceBiasNeg_type;
      _ForceBiasNeg_type ForceBiasNeg;
      typedef geometry_msgs::Vector3 _OriDeadbandPos_type;
      _OriDeadbandPos_type OriDeadbandPos;
      typedef geometry_msgs::Vector3 _OriDeadbandNeg_type;
      _OriDeadbandNeg_type OriDeadbandNeg;
      typedef geometry_msgs::Vector3 _OriStiffPos_type;
      _OriStiffPos_type OriStiffPos;
      typedef geometry_msgs::Vector3 _OriStiffNeg_type;
      _OriStiffNeg_type OriStiffNeg;
      typedef geometry_msgs::Vector3 _OriDampingPos_type;
      _OriDampingPos_type OriDampingPos;
      typedef geometry_msgs::Vector3 _OriDampingNeg_type;
      _OriDampingNeg_type OriDampingNeg;
      typedef geometry_msgs::Vector3 _TorqueBiasPos_type;
      _TorqueBiasPos_type TorqueBiasPos;
      typedef geometry_msgs::Vector3 _TorqueBiasNeg_type;
      _TorqueBiasNeg_type TorqueBiasNeg;

    prmCartesianImpedanceGains():
      header(),
      ForceOrientation(),
      ForcePosition(),
      TorqueOrientation(),
      PosDeadbandPos(),
      PosDeadbandNeg(),
      PosStiffPos(),
      PosStiffNeg(),
      PosDampingPos(),
      PosDampingNeg(),
      ForceBiasPos(),
      ForceBiasNeg(),
      OriDeadbandPos(),
      OriDeadbandNeg(),
      OriStiffPos(),
      OriStiffNeg(),
      OriDampingPos(),
      OriDampingNeg(),
      TorqueBiasPos(),
      TorqueBiasNeg()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->ForceOrientation.serialize(outbuffer + offset);
      offset += this->ForcePosition.serialize(outbuffer + offset);
      offset += this->TorqueOrientation.serialize(outbuffer + offset);
      offset += this->PosDeadbandPos.serialize(outbuffer + offset);
      offset += this->PosDeadbandNeg.serialize(outbuffer + offset);
      offset += this->PosStiffPos.serialize(outbuffer + offset);
      offset += this->PosStiffNeg.serialize(outbuffer + offset);
      offset += this->PosDampingPos.serialize(outbuffer + offset);
      offset += this->PosDampingNeg.serialize(outbuffer + offset);
      offset += this->ForceBiasPos.serialize(outbuffer + offset);
      offset += this->ForceBiasNeg.serialize(outbuffer + offset);
      offset += this->OriDeadbandPos.serialize(outbuffer + offset);
      offset += this->OriDeadbandNeg.serialize(outbuffer + offset);
      offset += this->OriStiffPos.serialize(outbuffer + offset);
      offset += this->OriStiffNeg.serialize(outbuffer + offset);
      offset += this->OriDampingPos.serialize(outbuffer + offset);
      offset += this->OriDampingNeg.serialize(outbuffer + offset);
      offset += this->TorqueBiasPos.serialize(outbuffer + offset);
      offset += this->TorqueBiasNeg.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->ForceOrientation.deserialize(inbuffer + offset);
      offset += this->ForcePosition.deserialize(inbuffer + offset);
      offset += this->TorqueOrientation.deserialize(inbuffer + offset);
      offset += this->PosDeadbandPos.deserialize(inbuffer + offset);
      offset += this->PosDeadbandNeg.deserialize(inbuffer + offset);
      offset += this->PosStiffPos.deserialize(inbuffer + offset);
      offset += this->PosStiffNeg.deserialize(inbuffer + offset);
      offset += this->PosDampingPos.deserialize(inbuffer + offset);
      offset += this->PosDampingNeg.deserialize(inbuffer + offset);
      offset += this->ForceBiasPos.deserialize(inbuffer + offset);
      offset += this->ForceBiasNeg.deserialize(inbuffer + offset);
      offset += this->OriDeadbandPos.deserialize(inbuffer + offset);
      offset += this->OriDeadbandNeg.deserialize(inbuffer + offset);
      offset += this->OriStiffPos.deserialize(inbuffer + offset);
      offset += this->OriStiffNeg.deserialize(inbuffer + offset);
      offset += this->OriDampingPos.deserialize(inbuffer + offset);
      offset += this->OriDampingNeg.deserialize(inbuffer + offset);
      offset += this->TorqueBiasPos.deserialize(inbuffer + offset);
      offset += this->TorqueBiasNeg.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "cisst_msgs/prmCartesianImpedanceGains"; };
    virtual const char * getMD5() override { return "e7496f2f1492fd454255a51e4f99f687"; };

  };

}
#endif
