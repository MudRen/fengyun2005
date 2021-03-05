// silencer@fy4 workgroup 


inherit VRM_SERVER;

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room(__DIR__"jq2-room");

	//迷宫的长和宽。 (5-100)
	set_maze_long(20,20);
	
	//设定迷宫单位间隔．
	set_maze_spacing(5);

	//迷宫房间里的npc.
	//note: this one is optional
//	set_maze_npcs(__DIR__"npc/w-sentry-1");

	//迷宫房间内放置 npc 的可能性(1-100)
	//note: this one is optional too, if not set, then default is 20 (1/5)
//	set_maze_npc_rate(100);

	//迷宫重建时间 pass in integer 以秒为单位
	//note: this one is optional, if not set then default is no refresh
	//if pass in 0, then means no refresh too.
	// this example means maze will be refreshed in 1 hour.
//	set_maze_refresh(3600);

	//入口方向(出口在对面)
	set_entry_dir("west");

	//入口与区域的连接方向
	set_link_entry_dir("west");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"jq2-entry");
	
	//入口的坐标(根据连接link_entry_room的那个真实room来定。
	set_link_entry_room_x(-30);
	set_link_entry_room_y(-15);
	set_link_entry_room_z(-20);
	

	//出口与区域的连接方向
	set_link_exit_dir("east");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"jq2-exit");

	//入口房间短描述
	set_entry_short("黑血甬道");

	//入口房间描述
	set_entry_desc(@LONG
这是一条长长的甬道，四周粘粘的淌着黑色的物事，似乎是血，似乎是油，地
上尸骨散落，暗绿色的磷光星星闪闪，些许把前行的路照了出来。
LONG
);

	//出口房间短描述
	set_exit_short("黑血甬道");

	//出口房间描述
	set_exit_desc(@LONG
地牢的尽头又是一条长长的甬道，四周粘粘的淌着黑色的物事，似乎是血，似
乎是油，地上尸骨散落，暗绿色的磷光星星闪闪，些许把前行的路照了出来。没人
知道这儿关押的是谁，连当值的守卫也只能在入口处偶尔听到里面传来几声似人似
鬼的惨呼声。
LONG
);

	//迷宫房间的短描述
	set_maze_room_short("离魂牢");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
牢中游弋着孤魂野鬼般的犯人，没有天日，没有纲常，没有知觉，没有意识， 
只有一心一意的杀戮，只有当地牢中响起尖锐的哨子声时，每一个幽魂才会知道 
主人要来给他们一个月的食物，饮水和不浑身爆裂而死的『极乐销魂丸』。牢中 
也只有一个出口，没有人知道那个如同太上老君般的仙风道骨的真人是如何而来 
的，莫非，他就是仙人？
LONG
);

	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
