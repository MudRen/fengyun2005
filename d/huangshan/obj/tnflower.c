#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(WHT"天女花"NOR, ({ "angel flower", "天女花" }) );
    set_weight(3);
    if( clonep() )
        set_default_object(__FILE__);
    else {
    	set("unit", "朵");
        set("long", "花由七片花瓣组成，外轮三片，淡粉红色，其余白色，微微张开，洁白淡雅。
轻风徐来，宛如仙女披着轻纱，翩翩起舞。\n");
		set("value", 3000);
    }
	::init_item();
}
