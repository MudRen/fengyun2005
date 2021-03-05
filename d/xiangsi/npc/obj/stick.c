#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name(HIB"十字龙头棍"NOR, ({ "dragon stick","stick" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "百年铁木的棍身，一直混黑圆匀的延伸下来，而隐隐的一条浮雕的龙，眦目\n欲裂张牙舞爪，就蜿蜒的盘旋腾空而上，于那端头，咧嘴欲啸。\n");
                set("value", 0);
                set("material", "iron");
				set("no_get",1);
				set("nodrop_weapon",1);
                set("wield_msg", "$N拄着$n，颤巍巍的立了起来。\n");
                set("unwield_msg", "$N叹了口气，放下了手中的$n。\n");
        }
        ::init_staff(125);
}

int init()
{
//	::init();
	set("weapon_wielded","拄");
}