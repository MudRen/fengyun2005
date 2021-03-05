// silencer@fy4 workgroup 


inherit VRM_SERVER;

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room(__DIR__"cave-room");

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
	set_entry_dir("north");

	//入口与区域的连接方向
	set_link_entry_dir("north");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"cave-entry");
	
	//入口的坐标(根据连接link_entry_room的那个真实room来定。
	set_link_entry_room_x(0);
	set_link_entry_room_y(-100);
	set_link_entry_room_z(-10);
	

	//出口与区域的连接方向
	set_link_exit_dir("south");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"cave-exit");

	//入口房间短描述
	set_entry_short("鬼窟入口");

	//入口房间描述
	set_entry_desc(@LONG
黑漆漆的山洞，两侧的石壁上生满了苔藓，摸起来又湿又滑。你向里面看了看，
隐约有些光线，不象是从石壁上透进来的，更象是闪烁的磷火。传说修道之人在打
坐之时，心底的邪恶迤念会化作鬼怪，这儿是不是就是它们的栖身之所呢？
LONG
);

	//出口房间短描述
	set_exit_short("暗道");

	//出口房间描述
	set_exit_desc(@LONG
在黑漆漆的阴影中忽然有了些亮光，像是烛火，虽然很弱，对你来说，就像是
一盏指路的灯。奇怪的是，随着你的越走越近，这亮光却越来越惨淡，不象是人间
的灯火，而是坟冢里跳跃的鬼火，你不由浑身起了一阵鸡皮疙瘩。
LONG
);

	//迷宫房间的短描述
	set_maze_room_short("鬼窟");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
一个黑漆漆的山洞，黑沉沉的一眼望不到底。两侧的石壁上生满了苔藓，摸起
来又湿又滑。这石洞似乎是人工开凿的，从四周的石壁上仍能看出斧凿的痕迹。洞
里不时传来奇怪的响动，似乎是有人在哭泣，又似乎是野兽的喘息声，你用力闻了
闻，好像还有些硫磺的味道。
LONG
);

	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
