#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "忘川台");
	set("long", @LONG
忘川台并不是威严的亭台，只是忘川河畔的小小的一个土丘，据说，孟婆汤的
水就是来自于这忘川河，不过许多人相信孟婆汤其实是用人的眼泪做的。。。。要
过奈何桥投生的鬼魂喝了孟婆汤之后，往往会到这儿静静地坐上一阵，把前世的所
有人和事忘记，这样才能够能再次投胎做人。
LONG
	);
	set("no_fight", 1);	
	set("exits", ([
        	"northwest"      : __DIR__"pingan",
	]) );
        set("no_meal","你忽然发现口中的食物饮水成了苦涩的浊泥，赶快哇哇地吐了出来。\n");
	set("objects", ([
	
	]) );

	set("coor/x",40);
	set("coor/y",-80);
	set("coor/z",-190);
	set("no_fight",1);
	setup();
}


int	init(){
	add_action("do_sit","sit");
}



int	do_sit()
{
   	object me;
   	int	s, amount, count;
     	
   	me = this_player();
   	if( me->is_fighting() )
      		return notify_fail("战斗中坐下来，想找死吗！\n");
   	if( me->is_busy() )
      		return notify_fail("你上一个动作还没有完成。\n");
   	me->perform_busy(2);
   	
   	count = me->query("KILLED");
   	s = (int)me->query_skill("perception", 1);
   	if( random(me->query("kar")) > 9) {
	      	if(s >= 50) {
	        	tell_object(me,WHT"你静静地坐下，脑海中空空荡荡，人世鬼蜮，对你来说已经是全无记挂的了。\n"NOR);
	         	return 1;
	      	} 
	      	
	      	if (s<= count *10){
	      		tell_object(me,CYN"你静静地坐下，回想起这辈子走过的路，死死生生，可能做到来去从容？\n"NOR);
	        	tell_object(me, "你的鬼谷之道好象长进了一些。\n");
	      		amount =  me->query("int") + me->query("cps")+s;
	      		if(amount < 1) amount = 1;
	      		me->improve_skill("perception", amount);
	      	} else
	      		tell_object(me,CYN"你静静地坐下，回想起这辈子走过的路，淡淡一笑。\n"NOR);
   	} else {
      		tell_object(me,CYN"你想静静地坐下，但却无法释怀。。死得可真冤啊！！\n"NOR);
      		
        }
   	return 1;
}