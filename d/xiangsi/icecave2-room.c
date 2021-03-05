// annie 07.2003
// dancing_faery@hotmail.com

inherit ROOM;
#include <ansi.h>

void 	setup_room_desc(object room,int length, int width, int x, int y) {
	
	int exit_number;
	
	exit_number= sizeof(room->query("exits"));
	
 	if (exit_number>2) {				// 	Crossroad
		room->set("pos","crossroad");
		room->set("short",HIR BLK"冰洞之中"NOR);
		room->set("long",@LONG
阵阵刺骨的寒气在冰洞中流动，不时有凛冽的风从洞里掠过，风中还带着些许
的腥气与微弱的鸣声。是前进？是后退？左面也是层叠的冰岩，右面也是丛生的雪
笋，相似的景物扰得你把持不定，心烦意乱。
LONG
	);
	} else 	if (exit_number==1) {				//	Deadend
		room->set("pos","deadend");
		room->set("short",HIR BLK"冰壁之前"NOR);
		room->set("long",@LONG
绕过支着洞顶的寒冰斜柱，正要前行，却发现正对着幽深的黑暗里竟也有人，
正持着火摺向这边行来。你心下一惊，定神看去，却发现那不过是一堵巨大的坚冰
镜壁，拦住了整条道路。冰壁上倒映着的似乎是你的影子，却又似乎正咧着嘴冲你
诡笑。
LONG
	);		
	} else {						//	Normal description
		room->set("pos","normal");
		room->set("short",HIR BLK"冰结小道"NOR);
		room->set("long",@LONG
小心翼翼的行进在这七尺高下的冰道上，还要不时提防磕到洞顶垂下的冰棱，
或是被地上凹凸不平的冰坑冰渣绊倒，有时隔着薄薄的冰层已可看见出口，前方却
又是偌大的冰石阻住去路。你越向前行，心里的惊慌弥漫得越紧，而所有的期望，
都寄托在手中明灭不定的微弱光芒之上。
LONG
	);
	}
}



void 	setup_npc_obj(object room,int length, int width, int x, int y)
{
		object icecave;
		int boss_x,boss_y;
		icecave = load_object(__DIR__"icecave");
		icecave->generate_maze2();
		boss_x = icecave->query("icecave2/boss_x");
		boss_y = icecave->query("icecave2/boss_y");

// 第二层怪物：雪域阴魂，雾影，奇邪，冰魔神
// 本层怪物随意散落。

		room->set("objects",([				
			__DIR__"mazenpc/shade":		random(80) < 20,
			__DIR__"mazenpc/mistfolk":	random(80) < 20,
			__DIR__"mazenpc/phantom":	random(80) < 20,
		]));		

	if (x == boss_x && y == boss_y)
	{
		room->delete("objects");
		room->set("boss_room",4);			// 1/4几率。
		room->set("ph",__DIR__"mazenpc/snowykirin");
		room->set("boss",__DIR__"mazenpc/icecream");
		room->set("refresh",2);				// maze 创造后 15min 生成boss/ph
	}

	room->setup();
}

int ph_here()
{
	object env,*inv;
	int i;
	env = this_object();
	inv = all_inventory(env);
	for (i=0;i<sizeof(inv) ; i++)
		if (inv[i]->query("real_boss") || inv[i]->query("real_ph"))	// 依然存活。
			return 1;

	return 0;
}

void reset()
{
	object npc;
	if (query("boss_room"))
	{
		set("pos","boss");
		set("short",WHT"冰洞之中"NOR);
		set("long",@LONG
行到这里，原本狭窄的冰壁却突向四面退去，让出了一块十几坪大的空地，而
周围的空气，也似是比方才更加刺骨冰寒。空地上飘荡着几点幽幽的荧光磷火，一
种难以言喻的压力充斥在四面八方，你心中不由得升起一股难以抑制的寒意，额上
沁出了粒粒冷汗。
LONG
	);

		if (!ph_here())
			add("refresh",-1);
		if (query("refresh") == 0)
		{
			if (!random(query("boss_room")))	
			{
				npc = new(query("boss"));
				npc->move(this_object());
				set("refresh",24);			// Boss死后6小时刷新。
			}
			else
			{
				npc = new(query("ph"));
				npc->move(this_object());
				set("refresh",8);			// 否则2小时刷新。
			}
		}
	}
	::reset();
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/
