// pink_cloth.c

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
	set_name(BLU"黑牡丹"NOR, ({ "black flower", "flower" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "清高冷傲的黑牡丹。\n");
		set("unit", "朵");
		set("value", 6);
		set("material", "plant");
		set("armor_prop/armor", 0);
		set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
		set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");
		set("female_only", 1);

	}
	::init_head();
//	call_out("wither",600);
}

void init(){
	if(!userp(environment(this_object()))){
		call_out("flower_gone", 1);
	}
	return;
}

int flower_gone(){
	message_vision("$N缓缓飘落，花朵迅速凋谢，转瞬间尘归尘，土归土不留一丝痕迹。\n", this_object());
	destruct(this_object());
	return 1;
}

void wither(){
	call_out("flower_fade", 600);
}

void flower_fade()
{
	if (query("delivery"))
	{
		set("name","枯萎的"+name());
		set("long","这原来是一朵"+query("long")+"不过现在已经枯萎了。\n");
		delete("delivery");
	}
}