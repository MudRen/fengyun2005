// poison 在武器上下毒。Sillencer@fy4 

#include <ansi.h>
inherit SSERVER;

int main (object me, string arg)
{
	object ob, herb;
    	int skill;
    	string h_name, obname;
	function f;
	
    	if(me->query("class")!="knight")
    		return notify_fail("只有快活林弟子才能够对兵器染毒。\n");

	skill = me->query_skill("dream-herb",1);
	if (skill < 75 || me->query_skill("herb")< 75)
		return notify_fail("对兵器染毒至少需要75级的云梦五花锦和药道。\n");

	if(!arg)
		return notify_fail("你要往什么兵器上面附加什么药草?\n");
	
	if(sscanf(arg,"%s %s",obname,h_name)!=2)
		return notify_fail("格式是 poison <兵器名> <药草名> \n");
		
	if(!objectp(herb = present(h_name,me)))
		return notify_fail("你身上没有这种药草。\n");
		
	if(!objectp(ob=present(obname,this_player())))
		return notify_fail("你身上没有这件武器。\n");
	
	if(!ob->query("weapon_prop"))
		return notify_fail(ob->name()+"不是兵器。\n");
	
	if (herb->query("type")!= "poison" || herb->query("material")!="herb")
		return notify_fail("这种药草不能在武器上染毒。\n");
	
	if (ob->query("skill_type") == "unarmed")
		return notify_fail("染毒不能使用在搏击的武器上。\n");
	
	if (herb->query("level")> skill)
		return notify_fail("你的云梦五花锦等级太低，还不能掌握这种药草的特性。\n");
		
	if (ob->query_temp("hit_ob",1))
		return notify_fail(ob->name()+"上已经有特殊特性了。\n");
		
	if (me->query("timer/apply_poison") + 10 > time())
		return notify_fail("歇口气再染毒吧。\n");
	
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
	
		
	f = (:call_other,"/obj/proc/proc_herb","hit_ob":);
	if(!functionp(f))
		return notify_fail("附加失败，请通知巫师检查。\n");
		
	ob->set_temp("hit_ob",bind(f,ob));
	ob->set_temp("herb/owner", me);
	ob->set_temp("herb/proc_rate",herb->query("proc"));
	ob->set_temp("herb/proc_amount",herb->query("effect"));
	ob->set_temp("herb/proc_type",herb->query("field"));
	
	if(ob->query_temp("hit_ob",1))
	{
		message_vision(HIB"$N小心翼翼地抓起一片"+herb->name()+ HIB"叶，在"+ob->name()+HIB"的开口处抹了一遍，\n"
				+ob->name() + HIB"的锋刃透出暗蓝色的光芒。\n"NOR, me);
	}
	else 
		tell_object(me,"附加失败，请通知巫师检查。\n");
	herb->add_amount(-1);
	call_out("remove_effect",180,ob);	// 3min duration, only owner can apply
	me->set("timer/apply_poison",time());
	me->perform_busy(1);
	return 1;
}


int remove_effect(object weapon)
{
	object holder;
	if(!weapon)	return 1;
	
	holder = environment(weapon);
	if(!holder) return 1;
	
	if(interactive(holder))	
		message_vision(CYN""+weapon->name()+CYN"的锋刃慢慢恢复了正常的光泽。\n"NOR,holder);
	else	
		message("vision",CYN""+weapon->name()+CYN"的锋刃慢慢恢复了正常的光泽。\n"NOR,holder);
	weapon->delete_temp("herb");
	weapon->delete_temp("hit_ob");
	return 1;
}


int help(object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	poison <兵器名> <药草名> [0m
[0;1;37m────────────────────────────────[0m   
快活林弟子的专长，利用药草在兵器上下毒。（需75级云梦五花锦和药道）。
在打斗中如果击中对方，则有一定几率（基础５０％）让对方受到额外伤害。

＃心神伤害药草：
无心海棠（L75、-75）单心海棠（L110、-150）三心海棠（L150、-200）
五心海棠（L180、-250）七心海棠（L200、-300）

＃ 气血伤害药草：
蓝花蛇草（L75、-75）绿花蛇草（L110、-150）白花蛇草（L150、-200）
黄花蛇草（L180、-250）红花蛇草（L200、-300）

＃精力伤害药草：
罂粟粉（L75、-75）罂粟叶（L110、-150）罂粟末（L150、-200）
罂粟萼（L180、-250）罂粟果（L200、-300）

上面前一个数字时所需云梦五花锦等级，后一个是伤害数值。
[0;1;37m────────────────────────────────[0m   
 
HELP
    );
    return 1;
}
 