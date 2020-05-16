#define	_COMMAND_C_

#include "command.h"
//#include "udp-app.h"
#include "rpl-dag-root.h"
#define DEBUG DEBUG_PRINT
#include "os/net/ipv6/uip-debug.h"

extern int gNodeID;

#define NOT_IMPLEMENTED return snprintf(buf, buflen, "NOT IMPLEMENTED")

//PROCESS_NAME(udp_client_process);
int cmd_start_udp(uint16_t id, char *buf, int buflen)
{
  NOT_IMPLEMENTED;
#if 0
  /* Just stsrt the periodic timer to send UDP traffic */
  int n=0;
  //process_start(&udp_client_process, NULL);
  start_udp_process();
  ADD2BUF(NULL, "UDP Client Sucess");
  return n;
#endif
}

/*
appstat->totalpktsent = seq_id;
  appstat->totalpktrecvd = g_pktstat.rcvcnt;
  appstat->totalduppkt = g_pktstat.dupcnt;
  appstat->minroudtriptime = g_pktstat.leastLatency;
  appstat->maxroundtriptime = g_pktstat.maxLatency;

*/
int cmd_get_udpapp_stat(uint16_t id, char *buf, int buflen)
{
  NOT_IMPLEMENTED;
#if 0
  udpapp_stat_t appstat;
  int n = 0;

  int isroot = rpl_dag_root_is_root();

  udp_get_app_stat(&appstat);
  if (isroot){
    ADD2BUF(NULL, "\t\"Total PKT Sent 2 BR\": \"%u\",\n", appstat.totalpktsent);
    ADD2BUF(NULL, "\t\"Total PKT Recvd by BR\": \"%u\",\n", appstat.totalpktrecvd);
    ADD2BUF(NULL, "\t\"Total PKT Dropped\": \"%u\",\n", (appstat.totalpktsent - appstat.totalpktrecvd));
    ADD2BUF(NULL, "\t\"Total Dup PKT RCVD by BR\": \"%u\",\n", appstat.totalduppkt);
    if (appstat.totalpktrecvd){
      ADD2BUF(NULL, "\t\"PDR for upward direction\": \"%.2f\",\n", (float)appstat.totalpktrecvd/(float)appstat.totalpktsent);
    }
  }
  else{
    ADD2BUF(NULL, "\t\"Node:\" \"%d\",\n",gNodeID);
    ADD2BUF(NULL, "\t\"Total REQ Sent\": \"%u\",\n", appstat.totalpktsent);

    ADD2BUF(NULL, "\t\"Total RSP Recvd\": \"%u\",\n", appstat.totalpktrecvd);
    ADD2BUF(NULL, "\t\"Total RSP Dropped\": \"%u\",\n", (appstat.totalpktsent - appstat.totalpktrecvd));
    ADD2BUF(NULL, "\t\"Total Dup RSP RCVD\": \"%u\",\n", appstat.totalduppkt);
    if (appstat.totalpktrecvd){
      ADD2BUF(NULL, "\t\"PDR for upward direction\": \"%.2f\",\n", (float)appstat.totalpktrecvd/(float)appstat.totalpktsent);
    }
    ADD2BUF(NULL, "\t\"Least E2E Latency\": \"%lu\",\n", appstat.minroudtriptime);
    ADD2BUF(NULL, "\t\"MAX E2E Latency\": \"%lu\",\n", appstat.maxroundtriptime);
  }
  return n;
#endif
}

int uip_ipaddr_to_str(const uip_ipaddr_t *addr, char *buf, int buflen)
{
#if NETSTACK_CONF_WITH_IPV6
	uint16_t a;
	unsigned int i;
	int f, n =0;
#endif /* NETSTACK_CONF_WITH_IPV6 */
	if(addr == NULL) {
		return snprintf(buf, buflen, "[NONE]");
	}
#if NETSTACK_CONF_WITH_IPV6
	for(i = 0, f = 0; i < sizeof(uip_ipaddr_t); i += 2) {
		a = (addr->u8[i] << 8) + addr->u8[i + 1];
		if(a == 0 && f >= 0) {
			if(f++ == 0) {
				n += snprintf(buf+n, buflen-n, "::");
			}
		} else {
			if(f > 0) {
				f = -1;
			} else if(i > 0) {
				n += snprintf(buf+n, buflen-n, ":");
			}
			n += snprintf(buf+n, buflen-n,"%x", a);
		}
	}
	return n;
#else /* NETSTACK_CONF_WITH_IPV6 */
	return snprintf(buf, buflen, "%u.%u.%u.%u",
			addr->u8[0], addr->u8[1], addr->u8[2], addr->u8[3]);
#endif /* NETSTACK_CONF_WITH_IPV6 */
}

int cmd_def_route(uint16_t id, char *buf, int buflen)
{
    uip_ipaddr_t *ipaddr = uip_ds6_defrt_choose();
    if (!ipaddr) {
        return snprintf(buf, buflen, "NO_DEF_ROUTE");
    }
	return uip_ipaddr_to_str(ipaddr, buf, buflen);
}

int cmd_rpl_stats(uint16_t id, char *buf, int buflen)
{
    NOT_IMPLEMENTED;
#if 0
	int n=0;
	//LOCK();
	ADD2BUF(NULL, "{ \"rpl_stats\": {\n");
	ADD2BUF(NULL, "\t\"mem_ovrflw\": \"%d\",\n", rpl_stats.mem_overflows);
	ADD2BUF(NULL, "\t\"local_repairs\": \"%d\",\n", rpl_stats.local_repairs);
	ADD2BUF(NULL, "\t\"global_repairs\": \"%d\",\n", rpl_stats.global_repairs);
	ADD2BUF(NULL, "\t\"malformed_msgs\": \"%d\",\n", rpl_stats.malformed_msgs);
	ADD2BUF(NULL, "\t\"resets\": \"%d\",\n", rpl_stats.resets);
	ADD2BUF(NULL, "\t\"parent_switch\": \"%d\",\n", rpl_stats.parent_switch);
	ADD2BUF(NULL, "\t\"fwd_errors\": \"%d\",\n", rpl_stats.forward_errors);
	ADD2BUF(NULL, "\t\"loop_errors\": \"%d\",\n", rpl_stats.loop_errors);
	ADD2BUF(NULL, "\t\"loop_warns\": \"%d\",\n", rpl_stats.loop_warnings);
	ADD2BUF(NULL, "\t\"root_repairs\": \"%d\",\n", rpl_stats.root_repairs);
	ADD2BUF(NULL, "\t\"dio_sent_mcast\": \"%d\",\n", rpl_stats.dio_sent_m);
	ADD2BUF(NULL, "\t\"dio_sent_ucast\": \"%d\",\n", rpl_stats.dio_sent_u);
	ADD2BUF(NULL, "\t\"dio_rcvd\": \"%d\",\n", rpl_stats.dio_recvd);
	ADD2BUF(NULL, "\t\"dao_sent\": \"%d\",\n", rpl_stats.dao_sent);
	ADD2BUF(NULL, "\t\"dao_rcvd\": \"%d\",\n", rpl_stats.dao_recvd);
	ADD2BUF(NULL, "\t\"dao_fwded\": \"%d\",\n", rpl_stats.dao_forwarded);
	ADD2BUF(NULL, "\t\"npdao_sent\": \"%d\",\n", rpl_stats.npdao_sent);
	ADD2BUF(NULL, "\t\"npdao_rcvd\": \"%d\",\n", rpl_stats.npdao_recvd);
	ADD2BUF(NULL, "\t\"npdao_fwded\": \"%d\",\n", rpl_stats.npdao_forwarded);
	ADD2BUF(NULL, "\t\"dco_sent\": \"%d\",\n", rpl_stats.dco_sent);
	ADD2BUF(NULL, "\t\"dco_rcvd\": \"%d\",\n", rpl_stats.dco_recvd);
	ADD2BUF(NULL, "\t\"dco_fwded\": \"%d\",\n", rpl_stats.dco_forwarded);
	ADD2BUF(NULL, "\t\"dco_ign\": \"%d\"\n", rpl_stats.dco_ignored);
	ADD2BUF(NULL, "}\n}");
#if 0
	n = snprintf(buf, buflen, "mem_ovrflw=%d,loc_rep=%d,glo_rep=%d,"
			"malformed_msgs=%d,resets=%d,prnt_sw=%d,"
			"fwd_err=%d,loop_err=%d,loop_warn=%d,root_rep=%d",
			rpl_stats.mem_overflows, rpl_stats.local_repairs, rpl_stats.global_repairs,
			rpl_stats.malformed_msgs, rpl_stats.resets, rpl_stats.parent_switch,
			rpl_stats.forward_errors, rpl_stats.loop_errors, rpl_stats.loop_warnings, rpl_stats.root_repairs);
#endif
	//UNLOCK();
	return n;
#endif
}

int cmd_node_osname(uint16_t id, char *buf, int buflen)
{
	int n=0;
	ADD2BUF(NULL, "{\"os\": \"contiki-ng\"}");
	return n;
}

int cmd_ipv6_stats(uint16_t id, char *buf, int buflen)
{
    NOT_IMPLEMENTED;
#if 0
	int n=0;
	//LOCK();
	ADD2BUF(NULL, "{ \"ipv6_stats\": {\n");
	ADD2BUF(NULL, "\t\"rcvd\": \"%d\",\n", uip_stat.ip.recv);
	ADD2BUF(NULL, "\t\"sent\": \"%d\",\n", uip_stat.ip.sent);
	ADD2BUF(NULL, "\t\"fwded\": \"%d\",\n", uip_stat.ip.forwarded);
	ADD2BUF(NULL, "\t\"drop\": \"%d\",\n", uip_stat.ip.drop);
	ADD2BUF(NULL, "\t\"drop\": \"%d\",\n", uip_stat.ip.drop);
	ADD2BUF(NULL, "\t\"ver_len_err\": \"%d\",\n",
		uip_stat.ip.vhlerr + uip_stat.ip.hblenerr + uip_stat.ip.lblenerr);
	ADD2BUF(NULL, "\t\"fragerr\": \"%d\",\n", uip_stat.ip.fragerr);
	ADD2BUF(NULL, "\t\"chkerr\": \"%d\",\n", uip_stat.ip.chkerr);
	ADD2BUF(NULL, "\t\"protoerr\": \"%d\"\n", uip_stat.ip.protoerr);
	ADD2BUF(NULL, "}\n}");
#if 0
	n = snprintf(buf, buflen, "ipv6 rcv=%d,sent=%d,fwded=%d,drop=%d,"
			"ver_len_err=%d,"
			"fragerr=%d,chkerr=%d,protoerr=%d",
			uip_stat.ip.recv, uip_stat.ip.sent, uip_stat.ip.forwarded, uip_stat.ip.drop,
			(uip_stat.ip.vhlerr + uip_stat.ip.hblenerr + uip_stat.ip.lblenerr),
			uip_stat.ip.fragerr, uip_stat.ip.chkerr, uip_stat.ip.protoerr);
	//UNLOCK();
#endif
	return n;
#endif
}

int cmd_icmp_stats(uint16_t id, char *buf, int buflen)
{
    NOT_IMPLEMENTED;
#if 0
	int n=0;
	ADD2BUF(NULL, "{ \"icmp_stats\": {\n");
	ADD2BUF(NULL, "\t\"rcvd\": \"%d\",\n", uip_stat.icmp.recv);
	ADD2BUF(NULL, "\t\"sent\": \"%d\",\n", uip_stat.icmp.sent);
	ADD2BUF(NULL, "\t\"drop\": \"%d\",\n", uip_stat.icmp.drop);
	ADD2BUF(NULL, "\t\"typeerr\": \"%d\",\n", uip_stat.icmp.typeerr);
	ADD2BUF(NULL, "\t\"chkerr\": \"%d\"\n", uip_stat.icmp.chkerr);
	ADD2BUF(NULL, "}\n}");
#if 0
	n = snprintf(buf, buflen, "icmpv6 rcv=%d,sent=%d,drop=%d,typeerr=%d,chkerr=%d",
			uip_stat.icmp.recv, uip_stat.icmp.sent, uip_stat.icmp.drop,
			uip_stat.icmp.typeerr, uip_stat.icmp.chkerr);
#endif
	return n;
#endif
}

int cmd_udp_stats(uint16_t id, char *buf, int buflen)
{
#if 0//UIP_CONF_UDP
	int n=0;
	ADD2BUF(NULL, "{ \"udp_stats\": {\n");
	ADD2BUF(NULL, "\t\"rcvd\": \"%d\",\n", uip_stat.udp.recv);
	ADD2BUF(NULL, "\t\"sent\": \"%d\",\n", uip_stat.udp.sent);
	ADD2BUF(NULL, "\t\"drop\": \"%d\",\n", uip_stat.udp.drop);
	ADD2BUF(NULL, "\t\"chkerr\": \"%d\"\n", uip_stat.udp.chkerr);
	ADD2BUF(NULL, "}\n}");
	return n;
#else
	return snprintf(buf, buflen, "UDP_NOT_ENABLED");
#endif
}

int cmd_tcp_stats(uint16_t id, char *buf, int buflen)
{
#if 0//UIP_CONF_TCP
	int n=0;
	ADD2BUF(NULL, "{ \"tcp_stats\": {\n");
	ADD2BUF(NULL, "\t\"rcvd\": \"%d\",\n", uip_stat.tcp.recv);
	ADD2BUF(NULL, "\t\"sent\": \"%d\",\n", uip_stat.tcp.sent);
	ADD2BUF(NULL, "\t\"drop\": \"%d\",\n", uip_stat.tcp.drop);
	ADD2BUF(NULL, "\t\"chkerr\": \"%d\",\n", uip_stat.tcp.chkerr);
	ADD2BUF(NULL, "\t\"ackerr\": \"%d\",\n", uip_stat.tcp.ackerr);
	ADD2BUF(NULL, "\t\"rst\": \"%d\",\n", uip_stat.tcp.rst);
	ADD2BUF(NULL, "\t\"rexmit\": \"%d\",\n", uip_stat.tcp.rexmit);
	ADD2BUF(NULL, "\t\"syndrop\": \"%d\",\n", uip_stat.tcp.syndrop);
	ADD2BUF(NULL, "\t\"synrst\": \"%d\"\n", uip_stat.tcp.synrst);
	ADD2BUF(NULL, "}\n}");
	return n;
#else
	return snprintf(buf, buflen, "TCP_NOT_ENABLED");
#endif
}

int cmd_nd6_stats(uint16_t id, char *buf, int buflen)
{
    NOT_IMPLEMENTED;
#if 0
	int n=0;
	ADD2BUF(NULL, "{ \"nd6_stats\": {\n");
	ADD2BUF(NULL, "\t\"rcvd\": \"%d\",\n", uip_stat.nd6.recv);
	ADD2BUF(NULL, "\t\"sent\": \"%d\",\n", uip_stat.nd6.sent);
	ADD2BUF(NULL, "\t\"drop\": \"%d\"\n", uip_stat.nd6.drop);
	ADD2BUF(NULL, "}\n}");
	return n;
#endif
}

int cmd_config_info(uint16_t id, char *buf, int buflen)
{
	int n=0;
	ADD2BUF(NULL, "{ \"config\": {\n");
	ADD2BUF(NULL, "\t\"rttable_maxsz\": \"%d\",\n", UIP_DS6_ROUTE_NB);
	ADD2BUF(NULL, "\t\"nbrtable_maxsz\": \"%d\"\n", NBR_TABLE_MAX_NEIGHBORS);
	ADD2BUF(NULL, "}\n}");
	return n;
}

int cmd_route_table(uint16_t id, char *buf, int buflen)
{
  int n=0;
  FILE *fp=NULL;

  if(buf && buf[0]) {
    fp = fopen(buf, "wt");
    if(!fp) {
      ADD2BUF(fp, "cmd_route_table: COULD NOT WRITE TO FILE:<%s>\n", buf);
      ERROR("cmd_route_table: COULD NOT WRITE TO FILE:<%s>\n", buf);
      return n;
    }
  }
  //LOCK();
  ADD2BUF(fp, "{ \"route_table\": {\n");
  ADD2BUF(fp, "\t\"routes\": [\n");
  n += get_route_list(fp, buf+n, buflen-n);
  ADD2BUF(fp, "]\n}}");
  //UNLOCK();
  if(fp) {
    fclose(fp);
    ADD2BUF(NULL, "SUCCESS");
  }
  return n;
}

