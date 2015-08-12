#include "create_topic.h"

void
create_string_topic(DDS_DomainParticipant dp,
                    DDS_Publisher p,
                    DDS_Subscriber s,
                    DDS_DataWriterQos *dwQos,
                    DDS_WaitSet w,
                    pingpong_PP_string_msgTypeSupport PP_string_dt,
                    DDS_Topic PP_string_topic,
                    DDS_DataWriter *PP_string_writer,
                    DDS_DataReader *PP_string_reader,
                    DDS_StatusCondition *PP_string_sc)
{
    pingpong_PP_string_msgTypeSupport_register_type(PP_string_dt, dp,
            "pingpong::PP_string_msg");
    PP_string_topic = DDS_DomainParticipant_create_topic(dp, "PP_string_topic",
            "pingpong::PP_string_msg", DDS_TOPIC_QOS_DEFAULT, NULL,
            DDS_STATUS_MASK_NONE);

    /* Create datawriter */
    *PP_string_writer = DDS_Publisher_create_datawriter(p, PP_string_topic,
            dwQos, NULL, DDS_STATUS_MASK_NONE);

    /* Create datareader */
    *PP_string_reader = DDS_Subscriber_create_datareader(s, PP_string_topic,
            DDS_DATAREADER_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);

    /* Add datareader statuscondition to waitset */
    *PP_string_sc = DDS_DataReader_get_statuscondition(*PP_string_reader);
    DDS_StatusCondition_set_enabled_statuses(*PP_string_sc, DDS_DATA_AVAILABLE_STATUS);
    DDS_WaitSet_attach_condition(w, *PP_string_sc);
}

void
create_min_topic(DDS_DomainParticipant dp,
                 DDS_Publisher p,
                 DDS_Subscriber s,
                 DDS_DataWriterQos *dwQos,
                 DDS_WaitSet w,
                 pingpong_PP_min_msgTypeSupport PP_min_dt,
                 DDS_Topic PP_min_topic,
                 DDS_DataWriter *PP_min_writer,
                 DDS_DataReader *PP_min_reader,
                 DDS_StatusCondition *PP_min_sc)
{

    pingpong_PP_min_msgTypeSupport_register_type(PP_min_dt, dp,
            "pingpong::PP_min_msg");
    PP_min_topic = DDS_DomainParticipant_create_topic(dp, "PP_min_topic",
            "pingpong::PP_min_msg", DDS_TOPIC_QOS_DEFAULT, NULL,
            DDS_STATUS_MASK_NONE);

    DDS_Publisher_get_default_datawriter_qos(p, dwQos);
    dwQos->reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
    dwQos->history.kind = DDS_KEEP_ALL_HISTORY_QOS;

    /* Create datawriter */
    *PP_min_writer = DDS_Publisher_create_datawriter(p, PP_min_topic, dwQos,
    NULL, DDS_STATUS_MASK_NONE);

    /* Create datareader */
    *PP_min_reader = DDS_Subscriber_create_datareader(s, PP_min_topic,
                       DDS_DATAREADER_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);

    /* Add datareader statuscondition to waitset */
    *PP_min_sc = DDS_DataReader_get_statuscondition(*PP_min_reader);
    DDS_StatusCondition_set_enabled_statuses(*PP_min_sc, DDS_DATA_AVAILABLE_STATUS);
    DDS_WaitSet_attach_condition(w, *PP_min_sc);
}

void
create_seq_topic(DDS_DomainParticipant dp,
                 DDS_Publisher p,
                 DDS_Subscriber s,
                 DDS_DataWriterQos *dwQos,
                 DDS_WaitSet w,
                 pingpong_PP_seq_msgTypeSupport PP_seq_dt,
                 DDS_Topic PP_seq_topic,
                 DDS_DataWriter *PP_seq_writer,
                 DDS_DataReader *PP_seq_reader,
                 DDS_StatusCondition *PP_seq_sc)
{
    pingpong_PP_seq_msgTypeSupport_register_type(PP_seq_dt, dp,
            "pingpong::PP_seq_msg");
    PP_seq_topic = DDS_DomainParticipant_create_topic(dp, "PP_seq_topic",
            "pingpong::PP_seq_msg", DDS_TOPIC_QOS_DEFAULT, NULL,
            DDS_STATUS_MASK_NONE);

    /* Create datawriter */
    *PP_seq_writer = DDS_Publisher_create_datawriter(p, PP_seq_topic, dwQos,
    NULL, DDS_STATUS_MASK_NONE);

    /* Create datareader */
    *PP_seq_reader = DDS_Subscriber_create_datareader(s, PP_seq_topic,
    DDS_DATAREADER_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);

    /* Add datareader statuscondition to waitset */
    *PP_seq_sc = DDS_DataReader_get_statuscondition(*PP_seq_reader);
    DDS_StatusCondition_set_enabled_statuses(*PP_seq_sc, DDS_DATA_AVAILABLE_STATUS);
    DDS_WaitSet_attach_condition(w, *PP_seq_sc);
}

void
create_fixed_topic(DDS_DomainParticipant dp,
                   DDS_Publisher p,
                   DDS_Subscriber s,
                   DDS_DataWriterQos *dwQos,
                   DDS_WaitSet w,
                   pingpong_PP_fixed_msgTypeSupport PP_fixed_dt,
                   DDS_Topic PP_fixed_topic,
                   DDS_DataWriter *PP_fixed_writer,
                   DDS_DataReader *PP_fixed_reader,
                   DDS_StatusCondition *PP_fixed_sc)
{
    pingpong_PP_fixed_msgTypeSupport_register_type(PP_fixed_dt, dp,
            "pingpong::PP_fixed_msg");
    PP_fixed_topic = DDS_DomainParticipant_create_topic(dp, "PP_fixed_topic",
            "pingpong::PP_fixed_msg", DDS_TOPIC_QOS_DEFAULT, NULL,
            DDS_STATUS_MASK_NONE);

    /* Create datawriter */
    *PP_fixed_writer = DDS_Publisher_create_datawriter(p, PP_fixed_topic, dwQos,
    NULL, DDS_STATUS_MASK_NONE);

    /* Create datareader */
    *PP_fixed_reader = DDS_Subscriber_create_datareader(s, PP_fixed_topic,
    DDS_DATAREADER_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);

    /* Add datareader statuscondition to waitset */
    *PP_fixed_sc = DDS_DataReader_get_statuscondition(*PP_fixed_reader);
    DDS_StatusCondition_set_enabled_statuses(*PP_fixed_sc, DDS_DATA_AVAILABLE_STATUS);
    DDS_WaitSet_attach_condition(w, *PP_fixed_sc);
}

void
create_array_topic(DDS_DomainParticipant dp,
                   DDS_Publisher p,
                   DDS_Subscriber s,
                   DDS_DataWriterQos *dwQos,
                   DDS_WaitSet w,
                   pingpong_PP_array_msgTypeSupport PP_array_dt,
                   DDS_Topic PP_array_topic,
                   DDS_DataWriter *PP_array_writer,
                   DDS_DataReader *PP_array_reader,
                   DDS_StatusCondition *PP_array_sc)
{
    pingpong_PP_array_msgTypeSupport_register_type(PP_array_dt, dp,
            "pingpong::PP_array_msg");
    PP_array_topic = DDS_DomainParticipant_create_topic(dp, "PP_array_topic",
            "pingpong::PP_array_msg", DDS_TOPIC_QOS_DEFAULT, NULL,
            DDS_STATUS_MASK_NONE);

    /* Create datawriter */
    *PP_array_writer = DDS_Publisher_create_datawriter(p, PP_array_topic, dwQos,
    NULL, DDS_STATUS_MASK_NONE);

    /* Create datareader */
    *PP_array_reader = DDS_Subscriber_create_datareader(s, PP_array_topic,
    DDS_DATAREADER_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);

    /* Add datareader statuscondition to waitset */
    *PP_array_sc = DDS_DataReader_get_statuscondition(*PP_array_reader);
    DDS_StatusCondition_set_enabled_statuses(*PP_array_sc, DDS_DATA_AVAILABLE_STATUS);
    DDS_WaitSet_attach_condition(w, *PP_array_sc);
}

void
create_bseq_topic(DDS_DomainParticipant dp,
                  DDS_Publisher p,
                  DDS_Subscriber s,
                  DDS_DataWriterQos *dwQos,
                  DDS_WaitSet w,
                  pingpong_PP_bseq_msgTypeSupport PP_bseq_dt,
                  DDS_Topic PP_bseq_topic,
                  DDS_DataWriter *PP_bseq_writer,
                  DDS_DataReader *PP_bseq_reader,
                  DDS_StatusCondition *PP_bseq_sc)
{
    pingpong_PP_bseq_msgTypeSupport_register_type(PP_bseq_dt, dp,
            "pingpong::PP_bseq_msg");
    PP_bseq_topic = DDS_DomainParticipant_create_topic(dp, "PP_bseq_topic",
            "pingpong::PP_bseq_msg", DDS_TOPIC_QOS_DEFAULT, NULL,
            DDS_STATUS_MASK_NONE);

    /* Create datawriter */
    *PP_bseq_writer = DDS_Publisher_create_datawriter(p, PP_bseq_topic, dwQos,
    NULL, DDS_STATUS_MASK_NONE);

    /* Create datareader */
    *PP_bseq_reader = DDS_Subscriber_create_datareader(s, PP_bseq_topic,
    DDS_DATAREADER_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);

    /* Add datareader statuscondition to waitset */
    *PP_bseq_sc = DDS_DataReader_get_statuscondition(*PP_bseq_reader);
    DDS_StatusCondition_set_enabled_statuses(*PP_bseq_sc, DDS_DATA_AVAILABLE_STATUS);
    DDS_WaitSet_attach_condition(w, *PP_bseq_sc);
}

void
create_quit_publish_topic(DDS_DomainParticipant dp,
                          DDS_Publisher p,
                          DDS_DataWriterQos *dwQos,
                          DDS_Topic PP_quit_topic,
                          DDS_DataWriter *PP_quit_writer,
                          pingpong_PP_quit_msgTypeSupport PP_quit_dt)
{
    pingpong_PP_quit_msgTypeSupport_register_type(PP_quit_dt, dp,
            "pingpong::PP_quit_msg");
    PP_quit_topic = DDS_DomainParticipant_create_topic(dp, "PP_quit_topic",
            "pingpong::PP_quit_msg", DDS_TOPIC_QOS_DEFAULT, NULL,
            DDS_STATUS_MASK_NONE);

    /* Create datawriter */
    *PP_quit_writer = DDS_Publisher_create_datawriter(p, PP_quit_topic, dwQos,
    NULL, DDS_STATUS_MASK_NONE);
}

void
create_quit_subscribe_topic(DDS_DomainParticipant dp,
                            DDS_Subscriber s,
                            DDS_Topic PP_quit_topic,
                            DDS_DataReader *PP_quit_reader,
                            pingpong_PP_quit_msgTypeSupport PP_quit_dt)
{
    pingpong_PP_quit_msgTypeSupport_register_type(PP_quit_dt, dp,
            "pingpong::PP_quit_msg");
    PP_quit_topic = DDS_DomainParticipant_create_topic(dp, "PP_quit_topic",
            "pingpong::PP_quit_msg", DDS_TOPIC_QOS_DEFAULT, NULL,
            DDS_STATUS_MASK_NONE);

    /* Create datareader */
    *PP_quit_reader = DDS_Subscriber_create_datareader (s, PP_quit_topic, DDS_DATAREADER_QOS_DEFAULT,
                                                       NULL, DDS_STATUS_MASK_NONE);
}
