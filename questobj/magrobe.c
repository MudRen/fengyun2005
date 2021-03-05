#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name(MAG"逍遥紫袍"NOR, ({ "magrobe" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("armor_prop/spells", 3);
                set("long", @LONG
逍遥侯家传之宝。当年逍遥侯的爷爷，在天山天池边上捉到一只千年冰蚕，他夫
人用冰蚕的丝做成了一件紫色的袍子。一般的千年动物的做的东西都有特殊的作
用，这件紫袍也不例外，紫袍穿在身上冬暖夏凉，刀枪不入，还可以驱除瘴气。     
LONG);
        }
	::init_cloth();
}
