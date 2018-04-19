/**
 * @file libtransistor/ld/module.h
 * @brief Module structure
 */

#pragma once

#include<libtransistor/collections/list.h>
#include<libtransistor/ld/elf.h>

#include<stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	MODULE_STATE_INVALID = 0,
	MODULE_STATE_QUEUED = 1,
	MODULE_STATE_SCANNED = 2,
	MODULE_STATE_RELOCATED = 3,
	MODULE_STATE_UNLOADED = 4,
} module_state_t;

typedef struct {
	module_t *module;
	trn_list_head_t list;
} module_list_node_t;

struct module_t {
	module_state_t state;
	int refcount;
	
	// needed for MODULE_STATE_QUEUED
	module_input_t input;

	trn_list_head_t dependencies;
	
	Elf64_Dyn *dynamic;
	Elf64_Sym *symtab;
	const char *strtab;
	uint32_t *hash;
};

#ifdef __cplusplus
}
#endif