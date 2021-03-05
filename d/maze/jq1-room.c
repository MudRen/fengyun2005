// Sinny-silencer@fy4 workgroup 

inherit ROOM;


void 	setup_room_desc(object room,int length, int width, int x, int y) {
	
	int exit_number;
	
	exit_number= sizeof(room->query("exits"));
	
	set("no_fly",1);
	
	if ( x == length-1 || y == width-1 || x = 0 || y == 0) {
		room->set("pos","edge");
		room->set("short","宣武门");			// 	Edge
		room->set("long",@LONG
上官与荆无命两人俱是嗜武如命之人，宣武堂即是两人时常前来训诫帮中得意 
弟子之处。堂中也时常会有名闻天下的武林名宿大家投靠金钱帮，而请至此堂给帮 
中众人宣武讲道。来到宣武门前，你简直无法相信这里竟在地下，灯火照得四下亮 
如白昼，方圆百丈之宽，金漆的铜门高达数丈。一块硕大的金匾刻着龙飞凤舞的一 
个“武”字。 
LONG
	);
	} else 	if (exit_number>2) {				// 	Crossroad
		room->set("pos","crossroad");
		room->set("short","忧患堂");
		room->set("long",@LONG
世人皆尘俗，忧患纷扰至。这里是武堂中的主堂“忧患堂”，若是没有机智的 
头脑，敏捷的身手，高人一等的胆识，到了忧患堂，可能连忧患的念头都来不及想 
时，便已命赴黄泉。上官一生自律清醒，常言唯忧患始知得失，由得失方晓成败。 
门下死士接受训诫的首条便是在忧患堂忍受各种非常人能忍受的考验。敏锐，身手， 
胆识。。。应有尽有。
LONG
	);
	} else 	if (exit_number==1) {				//	Deadend
		room->set("pos","deadend");
		room->set("short","杀戮堂");
		room->set("long",@LONG
金钱门下尽为奋不顾身的死士，江湖中闻之色变。概因每一名弟子都需在武堂 
中经历杀戮堂的考验，入此堂来，若不浴血鏖战，没有哪个弟子能活着走出来。与 
其他众堂不同，杀戮堂来路便是去路，若不杀出血路，等待你的，只有死路。
LONG
	);		
	} else {						//	Normal description
		room->set("pos","normal");
		room->set("short","贫贱堂");
		room->set("long",@LONG
上官早年家境贫寒，被父母卖入道院打杂，历尽人间屈辱贫贱，深晓金钱帮成 
为天下数一数二的帮会，其中的艰辛与不易。即使今日金钱帮富可敌国，上官也过 
着苦行僧般清苦的生活，门下弟子进得门来，若是无法在武堂中过得贫贱一关，赏 
罚堂堂主吴青自会将其逐出师门。
LONG
	);
	}
}

void 	setup_npc_obj(object room,int length, int width, int x, int y){
		
	int exit_number;
	exit_number= sizeof(room->query("exits"));
	
	if (x>=8) {
		room->set("objects",([				
			__DIR__"npc/jq1-guard2": 	!random(10),
			__DIR__"npc/jq1-guard3":	!random(10),
			__DIR__"npc/jq1-hyguard":	!random(5),
			__DIR__"npc/jq1-scorpion":	!random(10),
		]));		
	} else 	if (x>=4) {
		room->set("objects",([				
			__DIR__"npc/jq1-guard1": 	random(80)<50,
			__DIR__"npc/jq1-guard2":	!random(10),
			__DIR__"npc/jq1-scorpion":	!random(6),
		]));		
	}else  {
		room->set("objects",([				
			__DIR__"npc/jq1-guard2": 	!random(10),
			__DIR__"npc/jq1-scorpion": 	random(80)<50,
			__DIR__"npc/jq1-guard1":	!random(10),
		]));		
	}
	room->setup();
}


