// Silencer @ FY4 workgroup. Oct.2004

#include <weapon.h>
inherit WIELD;

void create() {
	if(clonep(this_object())) {
		destruct(this_object());
		return notify_fail("CAN NOT CLONE STARNDARD OBJECT!\n");
	}
}

varargs void init_fist(int damage, int flag) {
	if(!clonep()) {
		set("weapon_prop/damage", damage);
		set("nodrop_weapon",1);
		set("flag", flag | UNARMED_TWO_HANDED);
		set("weapon_wielded", W_FIST);
		set("skill_type", "unarmed");
		if(!query("verbs") ) {
			set("verbs", ({ "击","打" }) );
		}
	}
	::init_wield();
}

