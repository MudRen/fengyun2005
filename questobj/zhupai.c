#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(YEL"乱竹帖"NOR, ({ "luanzhu-tie" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "册");
            set("material", "bamboo");
	        set("long", @LONG
这是岁寒三友之青竹老人的信物，乃昔日青竹年少时以头发濡墨而作，如醉如痴，变乱挥放，百无禁忌。
LONG);
          }

    ::init_item();
}
