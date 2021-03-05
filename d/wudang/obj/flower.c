#include <armor.h>
inherit HEAD;

void create()
{
	string *names = ({
	        "红茶花", "抓破美人脸", "落第书生", "八仙过海",
	});
	
	set_name( names[random(sizeof(names))], ({ "flower" }));
	set_weight(30);
	if( clonep() ){
		set_default_object(__FILE__);
	} else {
		set("unit", "枝");
		set("value", 50);
		set("material", "wood");
		set("armor_prop/armor", 2);
	}
	::init_head();
}
