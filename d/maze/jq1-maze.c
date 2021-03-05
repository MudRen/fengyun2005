// silencer@fy4 workgroup 


inherit VRM_SERVER;

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room(__DIR__"jq1-room");

	//迷宫的长和宽。 (5-100)
	set_maze_long(14,14);
	
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
	set_entry_dir("west");

	//入口与区域的连接方向
	set_link_entry_dir("west");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"jq1-entry");
	
	//入口的坐标(根据连接link_entry_room的那个真实room来定。
	set_link_entry_room_x(-30);
	set_link_entry_room_y(-15);
	set_link_entry_room_z(-10);
	

	//出口与区域的连接方向
	set_link_exit_dir("east");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"jq1-exit");

	//入口房间短描述
	set_entry_short("宣武门");

	//入口房间描述
	set_entry_desc(@LONG
上官与荆无命两人俱是嗜武如命之人，宣武堂即是两人时常前来训诫帮中得意 
弟子之处。堂中也时常会有名闻天下的武林名宿大家投靠金钱帮，而请至此堂给帮 
中众人宣武讲道。来到宣武门前，你简直无法相信这里竟在地下，灯火照得四下亮 
如白昼，方圆百丈之宽，金漆的铜门高达数丈。一块硕大的金匾刻着龙飞凤舞的一 
个“武”字。
LONG
);

	//出口房间短描述
	set_exit_short("甬道");

	//出口房间描述
	set_exit_desc(@LONG
连接着迷宫般的殿堂，这儿是一条长长的甬道，两旁的警卫愈加森严。前面就
是宣武堂，原本是上官金虹每月一次的授武之处，数月前上官令人将此打扫一新，
搬入了几个身份不明的客人。。。。
LONG
);

	//迷宫房间的短描述
	set_maze_room_short("贫贱堂");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
上官早年家境贫寒，被父母卖入道院打杂，历尽人间屈辱贫贱，深晓金钱帮成 
为天下数一数二的帮会，其中的艰辛与不易。即使今日金钱帮富可敌国，上官也过 
着苦行僧般清苦的生活，门下弟子进得门来，若是无法在武堂中过得贫贱一关，赏 
罚堂堂主吴青自会将其逐出师门。
LONG
);

	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
