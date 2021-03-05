// silencer@fy4 workgroup 

#include <ansi.h>
inherit VRM_SERVER;

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room(__DIR__"taoyuan-room");

	//迷宫的长和宽。 (5-100)
	set_maze_long(12,12);
	
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
//	set_maze_refresh(7200);

	//入口方向(出口在对面)
	set_entry_dir("north");

	//入口与区域的连接方向
	set_link_entry_dir("north");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"taoyuan-entry");
	
	//入口的坐标(根据连接link_entry_room的那个真实room来定。
	set_link_entry_room_x(-60);
	set_link_entry_room_y(-10);
	set_link_entry_room_z(-10);
	

	//出口与区域的连接方向
	set_link_exit_dir("south");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"taoyuan-exit");

	//入口房间短描述
	set_entry_short(MAG"桃花林入口"NOR);

	//入口房间描述
	set_entry_desc(@LONG
自江湖中盛传已消失数十年的梅花盗重现江湖后，这片桃林便没有过安静的时
候，因为据说这“梅花盗”便时常出没在桃花林中，而自其人重现之日，这片原本
幽静的桃花林便笼上了一层厚厚的桃花瘴，不仅前路难辨，而且若是久呆其中，便
会身中花毒。
LONG
);

	//出口房间短描述
	set_exit_short(HIG"桃花林后"NOR);

	//出口房间描述
	set_exit_desc(@LONG
左转右转，也不知走了多少回头路，这无边的桃花林似乎到了尽头。树木逐渐
稀疏，花香却愈加浓郁了，透过花雾，你隐约看到前方似乎有一间小木屋，屋门半
掩，看不清里面是否住有人家。
LONG
);

	//迷宫房间的短描述
	set_maze_room_short("林间");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
繁花似锦，仿佛永无止尽的滚滚红尘迎面扑来。左边是花海，右侧是花海，来 
去的路，前方的路，蜿蜒消失在花海之中，后退还是往前？活路还是死路？你不禁 
满头冷汗，滴答而下。
LONG
);

	// 迷宫房间是否为户外房间？
	set_outdoors(1);
}
