// Sinny-silencer@fy4 workgroup 

inherit ROOM;


void 	setup_room_desc(object room,int length, int width, int x, int y) {
	
	int exit_number;
	
	exit_number= sizeof(room->query("exits"));
	
	set("no_fly",1);
	
	if ( x == length-1 || y == width-1 || x = 0 || y == 0) {
		room->set("pos","edge");
		room->set("short","林边");			// 	Edge
		room->set("long",@LONG
这是一片茂密的桃树林，林中芳草鲜美，落英缤纷，一层淡淡的薄雾，混合着 
青青的草香，弥漫在空气之中。适才所有的瘴气都一散而尽，四下安谧，偶尔的一 
两声鸟鸣，愈发地显出幽静来。这里的小路已被落花铺满，隐隐辨得出一丝痕迹。 
LONG
	);
	} else 	if (exit_number>2) {				// 	Crossroad
		room->set("pos","crossroad");
		room->set("short","林间");
		room->set("long",@LONG
四周桃花如烟似雾，粉红色的花雾弥漫在空气的每一处，初闻似是浓香可人， 
但时间一长，你不仅觉得胸口隐隐作痛，呼吸也逐渐困难起来。更加可怕的是，四 
周尽是桃树，不见尽头，而浓重的花雾中隐约闪现出点点的绿光蓝眸。。
LONG
	);
	} else 	if (exit_number==1) {				//	Deadend
		room->set("pos","deadend");
		room->set("short","绝径");
		room->set("long",@LONG
花径一转，原本开阔的树林，尽似到了个死路，除了来时的路，便只有无边无 
尽的桃花瘴和桃花林。浓雾越来越重，如同夜色笼罩一般，间或有一两点仿佛近在 
眼前又似远在天边的烛火摇曳飘荡
LONG
	);		
	} else {						//	Normal description
		room->set("pos","normal");
		room->set("short","林内");
		room->set("long",@LONG
繁花似锦，仿佛永无止尽的滚滚红尘迎面扑来。左边是花海，右侧是花海，来 
去的路，前方的路，蜿蜒消失在花海之中，后退还是往前？活路还是死路？你不禁 
满头冷汗，滴答而下。
LONG
	);
	}
}



void 	setup_npc_obj(object room,int length, int width, int x, int y){
		
	int exit_number;
	exit_number= sizeof(room->query("exits"));
	
	if (y<=4) {
		room->set("objects",([				
			__DIR__"npc/ty-redfox": 	!random(3),
			__DIR__"npc/ty-snake":		!random(2),
			__DIR__"npc/ty-redfox2":	!random(3),
			__DIR__"npc/ty-boss":		!random(3),
		]));		
	} else 	if (y<=7) {
		room->set("objects",([				
			__DIR__"npc/ty-rabbit": 	!random(3),
			__DIR__"npc/ty-butterfly":	!random(3),
			__DIR__"npc/ty-redfox":		!random(6),
			__DIR__"npc/ty-redfox2":	!random(5),
			__DIR__"npc/ty-snake":		!random(3),
			__DIR__"npc/ty-boss":		!random(3),
		]));		
	}else  {
		room->set("objects",([				
			__DIR__"npc/ty-deer":	 	!random(8),
			__DIR__"npc/ty-rabbit": 	!random(2),
			__DIR__"npc/ty-butterfly":	!random(2),
			__DIR__"npc/ty-redfox":		!random(5),
		]));		
	}
	room->setup();
}


