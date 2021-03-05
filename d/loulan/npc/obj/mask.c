#include <ansi.h>
inherit EQUIP;
void create()
{
	set_name(HIW"白飞飞的面具"NOR, ({ "mask" }) );
	set_weight(1);
	set("long","一个精巧的面具，巧夺天工，毫无瑕疵。\n");
	set("unit", "件");
	set("value", 1);
	set("material", "cloth");
	set("armor_type", "mask");
	set("fakegender", "女性");
	set("armor_prop/id", ({"bai feifei"}) );
	set("armor_prop/name", ({"白飞飞"}) );
    set("armor_prop/short", ({"幽灵宫主「"BLU"红尘有尽恨无常"NOR"」白飞飞(Bai feifei)"}) );
    set("armor_prop/long", ({"一个秀发如云，披散双肩的白衣少女。楚楚动人之态扣人心弦。白玉般的
身子如晶莹美玉，双腿圆润修长，柔软温暖的胸膛微微起伏着。。。\n"}) );
	
}