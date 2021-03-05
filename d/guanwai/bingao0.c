#include <ansi.h>

inherit ROOM;
void create()
{
	set("short", HIW"北坳"NOR);

	set("long", @LONG
这里是凸出来的山拗地区，风力最大，狂风卷着积雪，吹得人难以前进，喜玛
拉雅山诸峰，都是终年雪盖，只有这一处上面的山峰，因为经常被狂风吹刮，山峰
北麓，也即是正向着路人的这一面山坡，积雪被风吹得干干净净，露出朱红色的岩
石，与周围景色大不调和，更增荒冷寂寞之感，令人惊然生惧！                         
LONG);

	set("type","street");
	set("exits",([
        "up":__DIR__"bingao",
        "down": __DIR__"bingao1",
	]) );
	setup();
}

int valid_leave(object me, string dir)
{
	int dam_gin,dam_sen,dam_kee;
        dam_gin = me->query("max_gin")/6;
        dam_sen = me->query("max_sen")/6;
        dam_kee = me->query("max_kee")/6;
	
	if( userp(me) && dir == "up" )
	{
	    if ( me->query_skill("dodge",1) < 100 ) {
	        	if ((int)me->query("kee") <= 50) {
	        		message_vision("山冰如镜，狂风似刀，惊魂未定之间，$N但觉脚下一空，摔了下来......\n\n",me);
	        		me->unconcious();
	        	}
	        	else {
	        		me->start_busy(5);
	        		me->receive_damage("kee",50);
	        		me->set_temp("last_damage_from","在喜马拉亚峰失足落下，尸骨无存。\n");
	          		message_vision("山冰如镜，狂风似刀，$N只觉脚下无根，立足不稳......\n\n",me);
	          	}
	          	return notify_fail("\n");
	    }
		else {
	            switch ( random(18) ) {
	            	case 1:		
				if ((int)me->query("gin") < dam_gin || (int)me->query("kee") < dam_kee || (int)me->query("sen") < dam_sen) {
					message_vision(HIW"$N突然觉得脚下流冰浮动，四处哗哗作响，脚底一滑，竟已仰天摔了下去。\n"NOR,me);
					me->unconcious();
				}
				else {
					me->receive_damage("gin", dam_gin);
					me->receive_damage("kee", dam_kee);
					me->receive_damage("sen", dam_sen);
					me->set_temp("last_damage_from","在喜马拉亚峰失足落下，尸骨无存。\n");
					message_vision(HIW"$N突然觉得脚底一滑，竟仰天摔了一跤。\n"NOR,me);
				}
				return notify_fail("\n");
				break;
			case 2:
	    			message_vision(HIW"骤然之间，无数巨大的冰柱冰岩，在狂风中呼啸，炸裂，铺天盖地向$N头顶上砸来。。。\n\n"NOR,me);
				if ( random(2) )
				{
	        		message_vision(HIW"一块巨大无匹的冰石从天而降，砸向$N的额角，“轰。。。”\n"NOR,me);
					me->unconcious();
				}
				else
				{
	        		message_vision(HIW"$N全身紧贴在岩石下，紧紧抓着凸出来的冰笋，终于躲过冰块，却不由得惊出一身冷汗！\n\n"NOR,me);
				}
				return notify_fail("\n");
				break;
			case 3:
	    		message_vision(HIW"募地“轰隆”一声巨响，山摇地晃，闷雷阵阵，山崩了！\n\n"NOR,me);
				me->unconcious();
				return notify_fail("\n");
				break;
			case 4:
	    		message_vision(HIW"远处隐隐传来轰轰巨响，响声愈来愈近，愈来愈猛，转瞬之间竟\n然是一个愈来愈大的雪球从山上滚下！\n\n"NOR,me);
	   			message_vision(HIW"\n$N躲避不及，被大雪球紧紧的压在下边！\n\n"NOR,me);
	    		if( me->query_kar()<12 )
				{
					message_vision(HIW"$N浑身被压在冰块之中，血液都已被冻僵，眼前只是白芒芒的一片....\n\n"NOR,me);
					me->set_temp("last_damage_from","在喜马拉亚峰遭遇雪崩，尸骨无存。\n");
					me->die();
				}
	    			else if ( me->query_kar()<16)
				{
					message_vision(HIW"$N气若游丝，渐渐奈不住稀薄的空气，神智逐渐模糊起来....\n\n"NOR,me);
					me->unconcious();
				}
				else
				{
					message_vision(HIW"$N咬紧牙关，用尽全力往雪堆外挤，一寸，两寸......\n终于$N从雪堆里摇摇晃晃爬了出来......\n\n"NOR,me);
					me->start_busy(3);
				}
				return notify_fail("\n");
				break;
			}	
		}
	}
	return 1;
}