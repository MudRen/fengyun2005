
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object room,room2,who,*mem;
	int pwd, i, j,mm,count, max_exp, combatexp;
	string name; 
	object *dungeon_list;
	
	seteuid(getuid());
	
	// 由于我们不在实际Ｒｏｏｍ中留记号，所有进入操作必须由主人进行
	// This is the primary quest owner 
	if (me->query("private_maze/destination") == base_name(environment(me))+".c"
		 && me->query("quest/quest")== "垂笠老僧的任务" ) {
		
		if (me->query("quest_time")+ me->query("quest/duration")< time()) {
			tell_object(me,"太晚了，敌人已经闻风转移，这个任务失败了。\n");
			return 1;
		}
		
		if (!arg)
			who = me;
			else who = present(arg, environment(me));
		if (!who)
			return notify_fail("你的周围没有这个人。\n");
		
		if (!userp(who))
			return notify_fail("此人不愿意成为你的伙伴。\n");
				
		// If it's the first time, prepare the instance parameters for other people's entry.
		if (me->query("private_maze/create"))	{
			
		// 将原来的Dungeon销毁
			dungeon_list = children("/obj/dungeon/standardmaze");
//		CHANNEL_D->do_sys_channel("sys",sprintf("%O\n", dungeon_list));
			mm = sizeof(dungeon_list);
			for (i=0;i<mm;i++){
				if (dungeon_list[i]->query_owner()== me->query("id")) {
					dungeon_list[i]->refresh_maze();
				}
			}
						
			room2=load_object("/obj/dungeon/standardmaze/"+me->query("id")+"/entry");			
			if (!room2)	
				room2="/obj/dungeon/standardmaze"->query_maze_room(me->query("id")+"/entry");
			if (!room2) 
				return notify_fail("Oops.Please report to wizards. \n");	
		
			me->set("private_maze/create",0);	// 因为在销毁ｍａｚｅ时我们允许owner退出，所以必须限制create的次数．
						
			// Maze_exp 决定于队伍中最高的经验值，这样队伍中的人肯定能帮忙
			mem = pointerp(me->query_team()) ? me->query_team() : ({ me });
    		j = sizeof (mem);
    		while (j--)	{
				if (mem[j]) {
		    		max_exp = mem[j]->query("combat_exp");
		    		if (max_exp > 15000000) max_exp = 15000000;
		    		combatexp = (max_exp>combatexp) ? max_exp : combatexp;
				}
    		}
			room2->set("maze/exp", 	combatexp); 			

			room2->set("maze/type", me->query("private_maze/type"));
			room2->set("maze/exit", me->query("private_maze/destination"));
			room2->set("maze/name", me->query("private_maze/orig_name"));
			room2->set("maze/sig",	me->query("private_maze/maze"));
			room2->set("maze/npc_killed",me->query("private_maze/carried_npc"));
				me->delete("private_maze/carried_npc");
			
					room2->query("maze/sig")->set_link_exit_room(room2->query("maze/exit"));
					room2->query("maze/sig")->set_link_entry_room(room2->query("maze/exit"));

			room2->set("maze/boss",		"/obj/dungeon/boss");	
			room2->set("maze/blocker",	"/obj/dungeon/blocker");	
			room2->set("maze/npc_pfm_chance", me->query("private_maze/difficulty"));
			
			tell_object(me,sprintf("任务区域%s创建成功，允许进入最高等级为%s，最多人数%s人。\n",
						me->query("private_maze/orig_name"),
						chinese_number(F_LEVEL->get_level(room2->query("maze/exp")) +5),
						chinese_number(room2->query("maze/type"))));
							
		}
		
		room2 = find_object("/obj/dungeon/standardmaze/"+me->query("id")+"/entry");
		if (!room2 && !me->query("private_maze/create"))
			return notify_fail("你的任务已经结束或者过时，无法再进入／创建新地区。\n");
	
		if (F_LEVEL->get_level(who->query("combat_exp")) > F_LEVEL->get_level(room2->query("maze/exp")) +5)
			return notify_fail("进入该任务区的最高等级不能超过"+ (F_LEVEL->get_level(room2->query("maze/exp"))+5)+"。\n");
		
		count = sizeof(room2->get_players());
		if (count >= room2->query("maze/type"))
			return notify_fail("此任务甚为机密，不宜人多，已不能再进入了。\n");
		
//		me->set_temp("maze_entry",environment(me));	
		
		if (who->is_busy()|| who->is_fighting())
			return notify_fail("此人正处在忙乱中，无法移动。\n");
					
		who->move(room2);
		tell_object(who, WHT"\n进入"+me->name()+"的区域：" + me->query("private_maze/orig_name")+ "，你的任务是彻底摧毁这里。\n"NOR);
		if (who!=me)
			tell_object(me,WHT+who->name()+"已进入你的任务区域。\n"NOR);
		
//		tell_object(me,"file name is " + base_name(room2));		
		return 1;	
	}
	
	return 0;	
	
}

int help (object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[1;36m		entermaze [name] 	
[0;1;37m────────────────────────────────[0m   
 
该命令可进入进入自己或他人的任务区域，任务由垂笠老人给出。
接到任务后寻找到相关地点，使用该命令后便能进入一个独立的区域

对于持有任务者来说，只需输入 entermaze 便能进入

不同的任务区可能有不同的人数限制，在给出任务时会有相关说明。
人数上限高的，难度就会大一些，自然奖励也更高。

如果你觉得任务太难，想叫上些朋友来助阵，可以在入口处执行指令
entermaze id	其中id是朋友的英文名字

此任务没有组队限制，如果发现太难，可以随时拉个朋友来帮忙，在
入口处执行指令
entermaze id	其中id是朋友的英文名字
当然，朋友的经验等级不能比你的任务要求高太多。
完成任务后，奖励将由当时处在该任务区的所有人分享，若是单人任
务，也可以让人帮忙，当然，你自己就得不到奖励了。

任务区一般存在１５－３０分钟，时间到或者完成后自动销毁，销毁
后所有人、尸体移动到入口房间。


[0;1;37m────────────────────────────────[0m    
HELP
	);
	return 1;
}

