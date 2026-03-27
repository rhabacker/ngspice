/* Dummy implementations of the functions defined in vpi_user_dummy.h,
 * used to make a DLL to replace libvvp.DLL when linking, so that
 * Icarus Verilog need not be installed when linking components for it.
 */

#include <stdint.h>
#include "vpi_user_dummy.h"

#ifndef UNUSED
#define UNUSED(x) (void)(x)
#endif

PLI_INT32 vpi_printf(const char *, ...) {return 0;}
PLI_INT32 vpi_get_vlog_info(struct t_vpi_vlog_info *p) {UNUSED(p); return 0;}
void      vpi_get_time(vpiHandle h, struct t_vpi_time *p) {UNUSED(h); UNUSED(p);}
vpiHandle vpi_register_cb(struct t_cb_data *p) {UNUSED(p); return (void *)0;}
PLI_INT32 vpi_remove_cb(vpiHandle h) {UNUSED(h); return 0;}
PLI_INT32 vpi_free_object(vpiHandle h) {UNUSED(h); return 0;}

vpiHandle vpi_put_value(vpiHandle h, struct t_vpi_value *p1,
                        struct t_vpi_time *p2, PLI_INT32 i) {UNUSED(h); UNUSED(p1); UNUSED(p2); UNUSED(i); return (void *)0;}
char      *vpi_get_str(PLI_INT32 i, vpiHandle h) {UNUSED(i); UNUSED(h); return (char *)0;}
PLI_INT32  vpi_get(int, vpiHandle)  {return 0;}

vpiHandle  vpi_iterate(PLI_INT32, vpiHandle) {return (void *)0;}
vpiHandle  vpi_scan(vpiHandle) {return (void *)0;}
vpiHandle  vpi_handle_by_name(const char *, vpiHandle) {return (void *)0;}
void vpi_control(PLI_INT32 operation, ...) {UNUSED(operation);}
