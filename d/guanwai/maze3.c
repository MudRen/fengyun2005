#include <ansi.h>

inherit ROOM;
string *names=({
	__DIR__"maze3",
	__DIR__"maze3",
	__DIR__"maze5",
	__DIR__"maze1",
} );
void create()
{
	set("short", "冰雪世界");
	set("long", @LONG
这里充满了大大小小、形形色色的冰川，是大自然留给地球的不朽珍品。向四
周望去，全都是冰雪的世界。各种各样的冰塔分布在末端冰川表面，形态多样，构
成了群山中最奇丽的景观。高达数米的冰蘑菇被细细的冰柱支撑，摇摇欲坠。冰墙
陡峭直立，象巨大的屏风，让人生畏。最令人着迷的是无数冰塔拔地而起，有的象
锋利的宝剑，有的象古刹钟楼，还有冰桌、冰桥、冰柱、冰洞等等。这天然的冰雕
世界，都是经过阳光的不断雕塑而成，形成后又慢慢衰亡。
LONG
	);
        set("outdoors", "guanwai");
	set("coor/x",-30);
	set("coor/y",-70);
	set("coor/z",100);
	setup();
}
void reset()
{
	int i,j;
	string temp;
	::reset();
	for (i=0;i<=3;i++)
	{
		j=random(4);
		temp=names[j];
		names[j]=names[i];
		names[i]=names[j];
		names[i]=temp;
	}
	set("exits", ([
		"north" : names[0],
		"south" : names[1],
		"east" : names[2],
		"west" : names[3],
	]));
}

int valid_leave(object me, string dir)
{
	object *inv;
//      object ob;
        int i;
        int dam_gin,dam_sen,dam_kee;
        dam_gin = (int) me->query("max_gin")/10;
        dam_sen = (int) me->query("max_sen")/10;
        dam_kee = (int) me->query("max_kee")/10;

	if( userp(me) && dir == "south" )
	{
		inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                	if(inv[i]->query("bigcloth") && (int)inv[i]->query("equipped"))
	                        return 1;
	        }
                message_vision(HIW"山风越刮越大，夹着漫天风雪，冰刀一般割着$N每一寸肌肤......\n$N机凌凌的打了个冷战。\n"NOR,me);
                if((int)me->query("kee")<dam_kee ||(int)me->query("kee")<dam_kee||(int)me->query("kee")<dam_kee) {
                	me->unconcious();
                }
                else {
                	me->receive_damage("kee", dam_kee);
	                me->receive_damage("gin", dam_gin);
	                me->receive_damage("sen", dam_sen);
	                me->set_temp("last_damage_from","在关外冰雪世界饥寒交迫而死。\n");
	        }
        }
        else if( userp(me) )
        {
        	inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                	if(inv[i]->query("bigcloth") && (int)inv[i]->query("equipped"))
	                        return 1;
        	switch ( random(10) )
        	{
			case 1:			
				if((int)me->query("gin")<dam_gin) {
                			return notify_fail(HIW"阵阵寒风从你身边刮过，吹得你四肢麻木，寸步难行。\n"NOR);
					me->unconcious();
					break;
               			}
               			else {
               				me->receive_damage("gin", dam_gin);
               				me->set_temp("last_damage_from","在关外冰雪世界饥寒交迫而死。\n");
					me->start_busy(5);
					return notify_fail(HIW"阵阵寒风从你身边刮过，吹得你四肢麻木，寸步难行。\n"NOR);
					break;
				}
			case 2:
				me->set_temp("disable_inputs",1);
				me->set("disable_type",HIW "<冻僵中>"NOR);
				me->set_temp("is_unconcious",1);
				me->start_call_out( (: call_other, __FILE__, "remove_frozen",me :),random(20) );
				return notify_fail(HIW"寒风卷着冰雪，铺天盖地尽是白茫茫一片，你浑身积雪，似乎连血液\n都冻僵了...\n"NOR);
				break;
		}
	}
	return 1;
}

void remove_frozen(object me)
{
	me->delete("disable_type");
	me->delete_temp("disable_inputs");
	me->delete_temp("is_unconcious");
	if(!me->is_ghost())
	message_vision(HIR "\n\n$N奋起最后一点残余的力气，从积雪堆中爬了出来！！\n\n"NOR, me);
}