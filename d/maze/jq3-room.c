// Sinny-silencer@fy4 workgroup 
#include <ansi.h>
inherit ROOM;


void 	setup_room_desc(object room,int length, int width, int x, int y) {
	
	int exit_number;
	
	exit_number= sizeof(room->query("exits"));
	
	
	
	if ( x == length-1 || y == width-1 || x = 0 || y == 0) {
		room->set("pos","edge");
		room->set("short",YEL"显名门"NOR);			// 	Edge
		room->set("long",@LONG
名之于大多数人而言，或许比起利来，更为重要。威武尚不足以屈，贫贱尚 
不足以移，但一个“名”字，还有什么人不会被打倒的呢？任你绝世的剑客豪侠， 
任你绝世的美女佳人，还不是为了一个虚名？ 
LONG
	);
	} else 	if (exit_number>2) {				// 	Crossroad
		room->set("pos","crossroad");
		switch (random(2)) {
			case 0:	room->set("short",CYN"长生门"NOR);
				room->set("long",@LONG
任哪个人名利到了极至，自然都会妄图长生不老，永生不死。上官金虹也不 
例外，他本就是道士出身，于道家炼丹之术也颇有心得，因此这里也集中了从海 
内外搜集而来的灵丹妙药，应有尽有。 
LONG
	);
				break;
			case 1: room->set("short",HIY"财利门"NOR);
				room->set("long",@LONG
天下熙熙，皆为利来；天下攘攘，皆为利往。在上官眼里，没有谁不会被钱 
打动，没有什么是财利买不到的，没有什么是财利得不到的。金钱帮之所以自诩 
为金钱之帮，自然万事以金钱为首，以财利为之所欲。 
LONG
	);
		}

	} else 	if (exit_number==1) {				//	Deadend
		room->set("pos","deadend");
		room->set("short",MAG"喜欲门"NOR);
		room->set("long",@LONG
欲望，喜好，每个人都会有一已之欲，一已之好。而这一切，在上官金虹的 
眼里，无疑就是掌握天下的一个个筹码。 
LONG
	);		
	} else {						//	Normal description
		room->set("pos","normal");
		switch (random(2)) {
			case 0: room->set("short",GRN"安乐门"NOR);
				room->set("long",@LONG
金钱帮之所以在朝野内外无所羁绊，盖因为金钱帮筹建了庞大的妓院，赌场 
。。。控制着朝内的当权人物。官府根本不敢对金钱帮有所异动。因为谁若是有 
这个念头，那他肯定就不会见到第二天的朝阳。
LONG
	);
				break;
			case 1: room->set("short",HIY"尊荣门"NOR);
				room->set("long",@LONG
尊名荣华，固然在上官眼里，这一切是如此的轻易而不足为道，但在芸芸众 
生中，又有谁能逃得脱这两个字的诱惑呢
LONG
	);
		}
	
	
	}
}

void 	setup_npc_obj(object room,int length, int width, int x, int y){
		
	int exit_number;
	exit_number= sizeof(room->query("exits"));
	
	if (x>=20) {
		room->set("objects",([				
			__DIR__"npc/jq3-ass4": 		!random(5),
			__DIR__"npc/jq3-ass5": 		!random(5),
			__DIR__"npc/jq3-herald3": 	!random(8),
		]));		
	} else 	if (x>=10) {
		room->set("objects",([				
			__DIR__"npc/jq3-ass3": 		!random(5),
			__DIR__"npc/jq3-ass4": 		!random(5),
			__DIR__"npc/jq3-herald2": 	!random(8),
		]));		
	} else  {
		room->set("objects",([				
			__DIR__"npc/jq3-ass1": 		!random(5),
			__DIR__"npc/jq3-ass2": 		!random(5),
			__DIR__"npc/jq3-herald1": 	!random(8),
		]));		
	}
	room->setup();
}