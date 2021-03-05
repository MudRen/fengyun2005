// user list
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	string id, id2;
	object obj, old_obj,*pros,*pros_real;
	int i, remove_me;
	
	if (!arg)
		return notify_fail("指令格式 : baohu <对象>\n");
	
	if (userp(me))
	{
		if(!stringp(id=me->query("marry")))
			return notify_fail("你好象并没有结婚！\n");
		if(me->query("jiebai"))
			return notify_fail("你好象并没有结婚！\n");
			
		if (!objectp(obj=present(arg,environment(me))))
			return notify_fail("这儿有这个人吗？\n");
		if(id!= arg)
			return notify_fail(obj->name()+"好象并不是你的"+(me->query("gender") == "女性" ? "丈夫":"妻子")+"！\n");
		id2 = obj->query("marry");
		if( id2 != me->query("id"))
			return notify_fail(obj->name()+"好象并不是你的"+(me->query("gender") == "女性" ? "丈夫":"妻子")+"！\n");
		
		if (obj->query("divorced"))
			return notify_fail("你心念一动，想起"+obj->name(1)+"旧日之情事，不由踯躅起来。\n");
			
		pros = obj->query_temp("protectors");
		remove_me =0;
		for(i=0;i<sizeof(pros);i++)
			if(pros[i] == me) 
			{
			 pros -= ({ me });
			 remove_me =1;
			}
		if (remove_me) {
			me->delete_temp("protecting");
			obj->set_temp("protectors",pros);
			return notify_fail("你停止保护你的"+(me->query("gender") == "女性" ? "丈夫":"妻子")+obj->name()+"了！\n");	
		}
	
		if(sizeof(pros))
			pros += ({ me });
		else
			pros = ({ me });
		obj->set_temp("protectors",pros);
		write("你开始保护你的"+(me->query("gender") == "女性" ? "丈夫":"妻子")+obj->name()+"。\n");
		me->set_temp("protecting",obj);
		return 1;
	} else
	{
		if (!objectp(obj=present(arg,environment(me))))
			return notify_fail("这儿有这个人吗？\n");	
		if (!userp(obj))
			return notify_fail("你只能保护玩家。\n");
		if (obj == me)
			return notify_fail("保护自己？好主意！\n");
		
		// 去除旧的保护对象。	
		if (objectp(old_obj = me->query_temp("protecting")))
		{
			if (old_obj == obj)
				return notify_fail("你已经在保护"+ obj->name()+ "了。\n");
			pros = old_obj->query_temp("protectors");
			remove_me =0;
			for(i=0;i<sizeof(pros);i++)
			if(pros[i] == me) 
			{
		 		pros -= ({ me });
		 		remove_me =1;
			}	
			old_obj->set_temp("protectors",pros);
		}
		
		// Clean up a bit.lazy to count :D
		pros = obj->query_temp("protectors");
		for(i=0;i<sizeof(pros);i++)	
		{
			if(pros[i] == me) 
				pros -= ({ me });
		}
		
		if (sizeof(pros))
			pros += ({ me });
		else
			pros = ({ me });
		
		pros_real = ({});
		for(i=0;i<sizeof(pros);i++)	
		{
			if (pros[i])
				pros_real += ({ pros[i] });
		}
		
		me->set_temp("protecting", obj);
		obj->set_temp("protectors",pros_real);
	
		write("你开始保护"+obj->name()+"。\n");
		return 1;
	}
}

int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	baohu <对象>[0m
[0;1;37m────────────────────────────────[0m   

这是已婚夫妇用来保护对方（妻子／丈夫）的指令
当你成为保护者时，你可以用自己高超的拆招技能来保护
自己的同伴，替对方拆架敌人的攻击。

注意：
（１）保护伴侣时，自身也必须在比武战斗中。
（２）离婚再婚后有婚史的一方不能享受此优惠。

[0;1;37m────────────────────────────────[0m 
HELP
    );
    return 1;
}
