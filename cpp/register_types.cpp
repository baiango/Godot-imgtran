#include "register_types.hpp"


using namespace godot;

void initialize_classes(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
		return;
	// Paste your classes here
	ClassDB::register_class<Imgtran>();
}

void uninitialize_classes(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
		return;
}

// Unmangle the function name in the symbol by compile as C
extern "C" {
	// You need a GDExtensionBool function to connect to Godot
	// entry_symbol = "imgtran_init"
	GDExtensionBool GDE_EXPORT imgtran_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
		GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

		// Using function pointer to register constructor and deconstructor
		// so Godot can free your class
		init_obj.register_initializer(initialize_classes);
		init_obj.register_terminator(uninitialize_classes);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();
	}
}
