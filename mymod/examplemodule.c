#include "py/runtime.h"


// Minimal example: mymod.add(a, b) -> a+b
STATIC mp_obj_t mymod_add(mp_obj_t a_obj, mp_obj_t b_obj) {
mp_int_t a = mp_obj_get_int(a_obj);
mp_int_t b = mp_obj_get_int(b_obj);
return mp_obj_new_int(a + b);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(mymod_add_obj, mymod_add);


STATIC const mp_rom_map_elem_t mymod_module_globals_table[] = {
{ MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_mymod) },
{ MP_ROM_QSTR(MP_QSTR_add), MP_ROM_PTR(&mymod_add_obj) },
};
STATIC MP_DEFINE_CONST_DICT(mymod_module_globals, mymod_module_globals_table);


const mp_obj_module_t mymod_user_cmodule = {
.base = { &mp_type_module },
.globals = (mp_obj_dict_t *)&mymod_module_globals,
};


// Registered unconditionally. If you want to gate it, wrap in #if defined(MODULE_MYMOD_ENABLED)
MP_REGISTER_MODULE(MP_QSTR_mymod, mymod_user_cmodule);
