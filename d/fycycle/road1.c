#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "城西小路");
        set("long", @LONG
一条小路弯弯曲曲向北延伸。路的旁边是风云城的护城河，河的另外一边就是
高大的风云城城墙了。从这里可以看到城墙上值勤的士兵在站岗。河堤上长满了青
草。微风拂来一股泥土的气息。自从金钱帮在风云城里兴起以后，这里的行人渐渐
的多了起来，每天清晨都有金狮镖局的车队从此路过。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
//  "south" :"/d/quicksand/huangyie0",
	"south" : __DIR__"fywest",
  	"northeast" : __DIR__"road2",
	]));
         set("objects", ([
        __DIR__"obj/grass" : 1,
                        ]) );
        set("butterfly", 0);
        set("outdoors", "fengyun");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);


        setup();
}

void reset()
{
	object con, item, *inv;
	::reset();
	if( con = present("grass",this_object()))
	if( inv = all_inventory(con))
	if( !sizeof(inv)){
		item = new(__DIR__"obj/quant");
		item->move(con);
	}	
}

void init() {
	mixed *local;
	object me;
	int i, dayTime;
	
	
	local = NATURE_D->get_current_time();
	i = NATURE_D->get_season();
    	dayTime = local[5];
	me = this_player();
//	write(sprintf("%d", i));
	if(query("butterfly")) {
		return;
	}
	if ((i == 1 || i == 2) && dayTime > 720 && dayTime < 900 ) {
		if(random(10) == 1 && !me->query("宿命A/风云_蝴蝶")) {
			message_vision("\n一只蝴蝶从$N身边飞过，落在路边的野花上。\n\n", me);
			set("butterfly", 1);
			call_out("butterfly1", 5, me);
		} else if (random(10) > 5) {
			message_vision("\n一只蝴蝶从$N身边飞过，飞向了远处。\n\n", me);
		}
	}
}

int butterfly1(object me) {
	if (!me)	return 1;
	if(environment(me) == this_object()) {
		message_vision("\n蝴蝶越聚越多，路边的青草野花之间，成群的蝴蝶上下飞舞。有"HIR"暗红色的"NOR"，\n", 
				me);
		message_vision(HIB"亮蓝色的"NOR"，"HIY"黄色"NOR"带网样黑斑的，有绿色带凤尾飘带的....每一只蝴蝶飞过眼前，\n",
				me);
		message_vision("的时候，你都想仔细看清楚它精巧的图案花纹，可你又很快被飞过来的另一只更\n",
				me);
		message_vision("漂亮的吸引了注意力。\n", 
				me); 
		message_vision("\n众多的蝴蝶在你的身边的草丛之上翩翩起舞，令人目摇神驰。\n", me);
		call_out("butterfly2", 5, me);
	} else {
		set("butterfly", 0);
	}
}
int butterfly2(object me) {
	if (!me)	return 1;
	if(environment(me) == this_object()) {
		message("vision", HIY"\n忽然，有一只特别绚丽耀眼的蝴蝶飞入你的视线。它比别的蝴蝶都要大，\n"NOR, 
				me);
		message("vision", HIY"翅膀如玉般透明。很难说它是什么颜色的，因为在阳光下它不时变化着宝石般的色彩；\n"NOR,
				me);
		message("vision", HIY"也很难说它是什么图案，似乎有千万种美丽的图案在不停的幻动。 \n"NOR,
				me);
		message("vision", "\n它飞过来的姿势有一种飘缈的雍容。在如梦的飘忽中，你感觉不到有任何\n",
				me);
		message("vision", "兀突的动作。所有的飞行轨迹联成了一条条优美华丽的曲线。\n",
				me); 
		call_out("butterfly3", 5, me);
	} else {
		set("butterfly", 0);
	}
}

int butterfly3(object me) {
	if (!me)	return 1;
	if(environment(me) == this_object()) {
		message("vision", HIB"\n你忍不住占有的欲望，蹑手蹑脚的过去，想把它捉在手里。 \n"NOR,
				me);
		message("vision", me->name() + "蹑手蹑脚走向路边，像要捉什么。。。\n", 
				environment(me), me);
		message("vision", "\n你趁它停在一朵百合花上的时候，悄悄伸出手去... \n",
				me);
		message("vision", HIW"\n白色的百合花上，玉色蝴蝶的翅膀一张一合，这个图案的美丽，给你一种震撼，\n"NOR,
				me);
		message("vision", HIW"你知道，它将永远留在你记忆里。\n"NOR,
				me);
		call_out("butterfly4", 3, me);
	} else {
		set("butterfly", 0);
	}
}

int butterfly4(object me) {
	
	int num = 1+ random(10);
	if (!me)	return 1;
	if(environment(me) == this_object()) {	 
		message("vision", "\n你迟疑了一下，还是飞快伸出手，捏住了蝴蝶的翅膀！\n",
				me); 
		message("vision", HIM"\n就在你的手指碰到蝴蝶的一瞬间，玉色蝴蝶忽然变成碎片，如破碎的泡末般散开... \n"NOR,
				me);
		message("vision", HIM"如同打碎了如静水面的倒影，如同惊醒了一个黎明时分的好梦。\n"NOR,
				me);
		message("vision", "\n你不可置信地看着这一幕的发生，伸出的手还僵在那里。 \n",
				me);
		message("vision", HIG"\n没有风吹的飞舞。空中的碎片不断继续碎裂，成粉成砂，在阳光下折射着变幻的七彩，\n"NOR,
				me);
		message("vision", HIG"如同午睡惊醒时眼前明亮的朦胧。\n"NOR,
				me); 
		message("vision", me->name() + "直起腰，呆呆地站在路边。。。\n", environment(me), me);
		message("vision", HIC"在" + me->name() + "身边一团细粉末在阳光的折射下变幻着迷人的七彩。\n"NOR, 
				environment(me), me);
		message("vision", "\n蝴蝶群迅速的散去。\n",
				environment(me), me);
		set("butterfly", 0);	
		if (!me->query("宿命A/风云_蝴蝶")) {
			me->set("宿命A/风云_蝴蝶", num);
			log_file("riddle/FATE_LOG",
			sprintf("%s(%s) 得到宿命A/风云_蝴蝶 "+num+"。 %s \n",
				me->name(1), geteuid(me), ctime(time()) ));
		}	
			
	} else {
		set("butterfly", 0);
	}
}