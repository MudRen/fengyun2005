//TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIY "出跸刀" NOR, ({ "wood-wandao" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
        set("long", "一柄黄杨木雕的弯刀，无鞘，刀身长三尺半，上面雕有美人出跸图。\n据说这把刀具有非凡的魔力，但却无人参透。。。 \n");
        set("material", "wood");
        set("wield_msg", "$N默默地提起$n握在手中。\n");
                set("unwield_msg", "$N默默地放下手中的$n。\n");
		set("desc_ext","疗伤（cure wood-wandao）");
	}
	::init_blade(25);
}
void init()
{
        if(this_player()==environment())
        add_action("do_cure","cure");
}
int do_cure(string arg)
{
        object me;
        me = this_player();
        if (!arg)
                return notify_fail("你要用什么疗伤？\n");
    	if (arg != "wood-wandao")
                return notify_fail("你要用什么疗伤？\n");
        if (query("used")) 
                return notify_fail(this_object()->name()+"黯淡无光，黄木刀身隐隐现出一丝血痕，再也不能疗伤了。。。 \n");
       message_vision(HIR"$N默默将出跸刀紧紧贴至$N的鲜血淋漓的伤口处。。。\n"NOR,me);
       me->set("eff_kee",(int)me->query("max_kee"));
       me->set("eff_gin",(int)me->query("max_gin"));
       me->set("eff_sen",(int)me->query("max_sen"));
       message_vision(HIW"\n$N突然觉的伤口一凉，低头一看，原先血迹斑斑的伤口\n竟然已光滑如玉。。 \n\n"NOR,me);
        set("used",1);
        return 1;
}
