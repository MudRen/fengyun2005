// Sinny-silencer@fy4 workgroup 

inherit ROOM;


void 	setup_room_desc(object room,int length, int width, int x, int y) {
	
	int exit_number;
	
	exit_number= sizeof(room->query("exits"));
	
	set("no_fly",1);
	
	if ( x == length-1 || y == width-1 || x = 0 || y == 0) {
		room->set("pos","edge");
		room->set("short","黑血甬道");			// 	Edge
		room->set("long",@LONG
这是一条长长的甬道，四周粘粘的淌着黑色的物事，似乎是血，似乎是油，地
上尸骨散落，暗绿色的磷光星星闪闪，些许把前行的路照了出来。 
LONG
	);
	} else 	if (exit_number>2) {				// 	Crossroad
		room->set("pos","crossroad");
		room->set("short","损心牢");
		room->set("long",@LONG
这里是损心牢，囚禁的都是被药物控制，丧失心智的江湖高手；昔年叱咤风云， 
何等风光名利，今朝沦为阶下傀儡，唏嘘无尽；牢中淤臭十分，伸手不见五指的一 
格一格如同鸽子笼般的房间里时常传出鬼哭狼嚎般的嘶叫。
LONG
	);
	} else 	if (exit_number==1) {				//	Deadend
		room->set("pos","deadend");
		room->set("short","摧肝牢");
		room->set("long",@LONG
摧肝裂肺断人肠，牢中血污满地，尸骨如山。在金钱地牢里，犯人全被控制了 
心智，但都有自由，有自由活下去，而活下去的唯一方法便是让别人死掉，因为只 
有有了死人，才有新鲜的肉，才有鲜美的血，才有可以取暖的毛发。。。而所有能 
活下来的，无一不都是江湖中顶尖的高手。
LONG
	);		
	} else {						//	Normal description
		room->set("pos","normal");
		room->set("short","离魂牢");
		room->set("long",@LONG
牢中游弋着孤魂野鬼般的犯人，没有天日，没有纲常，没有知觉，没有意识， 
只有一心一意的杀戮，只有当地牢中响起尖锐的哨子声时，每一个幽魂才会知道 
主人要来给他们一个月的食物，饮水和不浑身爆裂而死的『极乐销魂丸』。牢中 
也只有一个出口，没有人知道那个如同太上老君般的仙风道骨的真人是如何而来 
的，莫非，他就是仙人？
LONG
	);
	}
}



void 	setup_npc_obj(object room,int length, int width, int x, int y){
		
	int exit_number;
	exit_number= sizeof(room->query("exits"));
	
	if (x>=14) {
		room->set("objects",([				
			__DIR__"npc/jq2-dead7": 	!random(5),
			__DIR__"npc/jq2-dead8": 	!random(5),
			__DIR__"npc/jq2-dead9": 	!random(5),
			__DIR__"npc/jq2-guard": 	!random(10),
			__DIR__"npc/jq2-boss": 		!random(10),
		]));		
	} else 	if (x>=7) {
		room->set("objects",([				
			__DIR__"npc/jq2-dead4": 	!random(5),
			__DIR__"npc/jq2-dead5": 	!random(5),
			__DIR__"npc/jq2-dead6": 	!random(5),
			__DIR__"npc/jq2-guard": 	!random(10),
		]));		
	}else  {
		room->set("objects",([				
			__DIR__"npc/jq2-dead1": 	!random(5),
			__DIR__"npc/jq2-dead2": 	!random(5),
			__DIR__"npc/jq2-dead3": 	!random(5),
			__DIR__"npc/jq2-guard": 	!random(10),
		]));		
	}
	room->setup();
}

