#ifndef __CREATE_TOPIC_H__
#define __CREATE_TOPIC_H__

#include "pingpong.h"

extern void
create_string_topic(DDS_DomainParticipant dp,
                    DDS_Publisher p,
                    DDS_Subscriber s,
                    DDS_DataWriterQos *dwQos,
                    DDS_WaitSet w,
                    pingpong_PP_string_msgTypeSupport PP_string_dt,
                    DDS_Topic PP_string_topic,
                    DDS_DataWriter *PP_string_writer,
                    DDS_DataReader *PP_string_reader,
                    DDS_StatusCondition *PP_string_sc);

extern void
create_min_topic(DDS_DomainParticipant dp,
                 DDS_Publisher p,
                 DDS_Subscriber s,
                 DDS_DataWriterQos *dwQos,
                 DDS_WaitSet w,
                 pingpong_PP_min_msgTypeSupport PP_min_dt,
                 DDS_Topic PP_min_topic,
                 DDS_DataWriter *PP_min_writer,
                 DDS_DataReader *PP_min_reader,
                 DDS_StatusCondition *PP_min_sc);

extern void
create_seq_topic(DDS_DomainParticipant dp,
                 DDS_Publisher p,
                 DDS_Subscriber s,
                 DDS_DataWriterQos *dwQos,
                 DDS_WaitSet w,
                 pingpong_PP_seq_msgTypeSupport PP_seq_dt,
                 DDS_Topic PP_seq_topic,
                 DDS_DataWriter *PP_seq_writer,
                 DDS_DataReader *PP_seq_reader,
                 DDS_StatusCondition *PP_seq_sc);

extern void
create_fixed_topic(DDS_DomainParticipant dp,
                   DDS_Publisher p,
                   DDS_Subscriber s,
                   DDS_DataWriterQos *dwQos,
                   DDS_WaitSet w,
                   pingpong_PP_fixed_msgTypeSupport PP_fixed_dt,
                   DDS_Topic PP_fixed_topic,
                   DDS_DataWriter *PP_fixed_writer,
                   DDS_DataReader *PP_fixed_reader,
                   DDS_StatusCondition *PP_fixed_sc);

extern void
create_array_topic(DDS_DomainParticipant dp,
                   DDS_Publisher p,
                   DDS_Subscriber s,
                   DDS_DataWriterQos *dwQos,
                   DDS_WaitSet w,
                   pingpong_PP_array_msgTypeSupport PP_array_dt,
                   DDS_Topic PP_array_topic,
                   DDS_DataWriter *PP_array_writer,
                   DDS_DataReader *PP_array_reader,
                   DDS_StatusCondition *PP_array_sc);

extern void
create_bseq_topic(DDS_DomainParticipant dp,
                  DDS_Publisher p,
                  DDS_Subscriber s,
                  DDS_DataWriterQos *dwQos,
                  DDS_WaitSet w,
                  pingpong_PP_bseq_msgTypeSupport PP_bseq_dt,
                  DDS_Topic PP_bseq_topic,
                  DDS_DataWriter *PP_bseq_writer,
                  DDS_DataReader *PP_bseq_reader,
                  DDS_StatusCondition *PP_bseq_sc);

extern void
create_quit_publish_topic(DDS_DomainParticipant dp,
                          DDS_Publisher p,
                          DDS_DataWriterQos *dwQos,
                          DDS_Topic PP_quit_topic,
                          DDS_DataWriter *PP_quit_writer,
                          pingpong_PP_quit_msgTypeSupport PP_quit_dt);

extern void
create_quit_subscribe_topic(DDS_DomainParticipant dp,
                            DDS_Subscriber s,
                            DDS_Topic PP_quit_topic,
                            DDS_DataReader *PP_quit_reader,
                            pingpong_PP_quit_msgTypeSupport PP_quit_dt);

#endif /* __CREATE_TOPIC_H__ */
