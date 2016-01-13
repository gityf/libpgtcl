/*-------------------------------------------------------------------------
 *
 * pgtclId.h
 *
 *	Contains Tcl "channel" interface routines, plus useful routines
 *	to convert between strings and pointers.  These are needed because
 *	everything in Tcl is a string, but in C, pointers to data structures
 *	are needed.
 *
 * Portions Copyright (c) 1996-2003, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * $Id: pgtclId.h,v 1.11 2005/11/27 12:46:06 karl Exp $
 *
 *-------------------------------------------------------------------------
 */

#ifndef CONST84
#     define CONST84
#endif


extern int PgSetConnectionId(Tcl_Interp *interp, PGconn *conn, char *connhandle);

#define DRIVER_OUTPUT_PROTO ClientData cData, CONST84 char *buf, int bufSize, \
	int *errorCodePtr
#define DRIVER_INPUT_PROTO ClientData cData, char *buf, int bufSize, \
	int *errorCodePtr
#define DRIVER_DEL_PROTO ClientData cData, Tcl_Interp *interp

extern PGconn *PgGetConnectionId(Tcl_Interp *interp, CONST84 char *id,
				  Pg_ConnectionId **);
extern int	PgDelConnectionId(DRIVER_DEL_PROTO);
extern int	PgOutputProc(DRIVER_OUTPUT_PROTO);
extern int	PgInputProc(DRIVER_INPUT_PROTO);
extern int	PgSetResultId(Tcl_Interp *interp, CONST84 char *connid, PGresult *res);
extern PGresult *PgGetResultId(Tcl_Interp *interp, CONST84 char *id, Pg_resultid **resultidPtr);
extern void PgDelResultId(Tcl_Interp *interp, CONST84 char *id);
extern int	PgGetConnByResultId(Tcl_Interp *interp, CONST84 char *resid);
extern void PgStartNotifyEventSource(Pg_ConnectionId * connid);
extern void PgStopNotifyEventSource(Pg_ConnectionId * connid, pqbool allevents);
extern void PgNotifyTransferEvents(Pg_ConnectionId * connid);
extern void PgConnLossTransferEvents(Pg_ConnectionId * connid);
extern void PgNotifyInterpDelete(ClientData clientData, Tcl_Interp *interp);

extern int PgConnCmd(ClientData cData, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[]);
extern void PgDelCmdHandle(ClientData cData);
extern void PgDelResultHandle(ClientData cData);

extern Tcl_ChannelType Pg_ConnType;
