// silencer@fy4 workgroup 


inherit VRM_SERVER;

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room(__DIR__"sl-room");

	//迷宫的长和宽。 (5-100)
	set_maze_long(25,25);
	
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
	set_link_entry_room(__DIR__"sl-entry");
	
	//入口的坐标(根据连接link_entry_room的那个真实room来定。
	set_link_entry_room_x(0);
	set_link_entry_room_y(-100);
	set_link_entry_room_z(-10);
	

	//出口与区域的连接方向
	set_link_exit_dir("east");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"sl-exit");

	//入口房间短描述
	set_entry_short("一百零八罗汉堂");

	//入口房间描述
	set_entry_desc(@LONG
走过夜叉殿，便是少林的一百零八罗汉堂，每堂都有德高望重，武艺精湛的少
林高僧把持，少林寺执天下武林执牛耳，虽说僧人少涉江湖，好事之徒或求艺，或
既图谋不轨私闯者络绎不绝。罗汉堂既是考证僧人武功的所在，也是少林防范外盗
的重地。
LONG
);

	//出口房间短描述
	set_exit_short("罗汉殿后");

	//出口房间描述
	set_exit_desc(@LONG
历经千辛万苦，终于闯出了这迷宫一般的一百零八罗汉堂，还来不及松口气，
前面便是帝释天殿，亦是力闯少林的最后一关。
LONG
);

	//迷宫房间的短描述
	set_maze_room_short("迦楼罗殿");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
迦楼罗为一大鸟，翅有庄严宝色，头生大瘤，为如意珠，此鸟鸣声悲苦，以龙 
为食。日嗜一龙及五百小龙。命终日，诸龙吐毒，无法再吃，于是上下翻飞七次， 
至金刚轮山顶上命终。因为其一生以龙为食物，体内积蓄毒气极多，临死时毒发 
自焚。肉身烧去后只余一心，作纯青琉璃色。
LONG
);

	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
