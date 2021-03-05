// silencer@fy4 workgroup 


inherit VRM_SERVER;

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room(__DIR__"jq3-room");

	//迷宫的长和宽。 (5-100)
	set_maze_long(30,30);
	
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
//	set_maze_refresh(86400);

	//入口方向(出口在对面)
	set_entry_dir("west");

	//入口与区域的连接方向
	set_link_entry_dir("west");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"jq3-entry");
	
	//入口的坐标(根据连接link_entry_room的那个真实room来定。
	set_link_entry_room_x(-10);
	set_link_entry_room_y(-9);
	set_link_entry_room_z(10);
	

	//出口与区域的连接方向
	set_link_exit_dir("east");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"jq3-exit");

	//入口房间短描述
	set_entry_short("显名门");

	//入口房间描述
	set_entry_desc(@LONG
名之于大多数人而言，或许比起利来，更为重要。威武尚不足以屈，贫贱尚 
不足以移，但一个“名”字，还有什么人不会被打倒的呢？任你绝世的剑客豪侠， 
任你绝世的美女佳人，还不是为了一个虚名？ 
LONG
);

	//出口房间短描述
	set_exit_short("黄金塔前");

	//出口房间描述
	set_exit_desc(@LONG
连绵不断的殿堂转得你头昏脑胀，无尽的财富，灼手的地位，旷世的武功，
多情的女伴，世上有谁能经得起着这样的诱惑？不知觉地面前忽然开阔起来，一
座五层的高塔，闪闪发光地耸立在空地上。
LONG
);

	//迷宫房间的短描述
	set_maze_room_short("安乐门");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
金钱帮之所以在朝野内外无所羁绊，盖因为金钱帮筹建了庞大的妓院，赌场 
。。。控制着朝内的当权人物。官府根本不敢对金钱帮有所异动。因为谁若是有 
这个念头，那他肯定就不会见到第二天的朝阳。
LONG
);

	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
