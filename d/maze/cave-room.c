// silencer@fy4 workgroup 五行阵之木阵

inherit ROOM;


void 	setup_room_desc(object room,int length, int width, int x, int y) {
	
	int exit_number;
	
	exit_number= sizeof(room->query("exits"));
	
	set("no_fly",1);
	
	if ( x == length-1 || y == width-1 || x = 0 || y == 0) {
		room->set("pos","edge");
		room->set("short","鬼窟");			// 	Edge
		room->set("long",@LONG
这儿是洞穴的边缘，周围要干燥许多，泥土是褚红色的，角落里偶尔会有些废
弃的木架和破罐破盆，显然曾经有人来过。你仔细往洞壁上看，依稀还可以辨认出
一些蝌蚪样的文字，似乎是道士做法时划的符咒。
LONG
	);
	} else 	if (exit_number>2) {				// 	Crossroad
		room->set("pos","crossroad");
		room->set("short","鬼窟");
		room->set("long",@LONG
面前的洞穴忽然分出了岔道，每一条都是黑漆漆的，像一个张开着血盆大口的
猛兽在等待着探险者。脚下忽然踢到几个骷髅，你吓了一条，不由心升悔意，然而
已经没有回头的路了，鬼窟似迷宫也般罩住了每一个不速之客。
LONG
	);
	} else 	if (exit_number==1) {				//	Deadend
		room->set("pos","deadend");
		room->set("short","鬼窟");
		room->set("long",@LONG
洞里是如此的漆黑，撞到石壁你才发现这里原来是条死路，洞顶的石钟乳滴滴
答答的水珠掉在颈项里让你打了个冷战，还是快些另找出路吧。
LONG
	);		
	} else {						//	Normal description
		room->set("pos","normal");
		room->set("short","鬼窟");
		room->set("long",@LONG
一个黑漆漆的山洞，黑沉沉的一眼望不到底。两侧的石壁上生满了苔藓，摸起
来又湿又滑。这石洞似乎是人工开凿的，从四周的石壁上仍能看出斧凿的痕迹。洞
里不时传来奇怪的响动，似乎是有人在哭泣，又似乎是野兽的喘息声，你用力闻了
闻，好像还有些硫磺的味道。
LONG
	);
	}
}



void 	setup_npc_obj(object room,int length, int width, int x, int y){
		
	int exit_number;
	exit_number= sizeof(room->query("exits"));
	
	if (y<=8) {
		room->set("objects",([				
			__DIR__"npc/cv-beast3":	 	!random(5),
			__DIR__"npc/cv-bug3": 		!random(5),
			__DIR__"npc/cv-devil3":		!random(5),
			__DIR__"npc/cv-boss":		!random(10),
		]));		
	} else 	if (y<=15) {
		room->set("objects",([				
			__DIR__"npc/cv-beast2":	 	!random(5),
			__DIR__"npc/cv-bug2": 		!random(5),
			__DIR__"npc/cv-bug1": 		!random(3),
			__DIR__"npc/cv-beast1":		!random(3),
			__DIR__"npc/cv-devil1":		!random(8),
			__DIR__"npc/cv-devil2":		!random(8),
		]));		
	}else  {
		room->set("objects",([				
			__DIR__"npc/cv-devil1":		!random(3),
			__DIR__"npc/cv-devil2":		!random(3),
			__DIR__"npc/cv-bug1": 		!random(6),
			__DIR__"npc/cv-beast1":		!random(6),
		]));		
	}
	room->setup();
}


void	init(){
	
}

