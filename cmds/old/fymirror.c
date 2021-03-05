// mudlist.c

#include <net/daemons.h>
#include <net/macros.h>

inherit F_CLEAN_UP;

#define	SYNTAX	"指令格式：fymirror\n"
int num_players(string mudname);
int main(object me, string arg)
{
	mapping mud_list;
	mapping mud_svc;
	mixed *muds;
	string output;
	int loop, size;

	if( !find_object(DNS_MASTER) )
		return notify_fail("网路精灵并没有被载入，请先将网路精灵载入。\n");

	//	Obtain mapping containing mud data
	mud_list = (mapping)DNS_MASTER->query_muds();

	// so we recognise ourselves as a DNS mud
	mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

	if(!mud_list)
		return notify_fail( MUD_NAME + "目前并没有跟网路上其他 Mud 取得联系。\n");

	//	Get list of all mud names within name server
	muds = keys( mud_list ) - ({ "DEFAULT" });

	//	Place mudlist into alphabetical format
	muds = sort_array(muds, 1);
	output = "Mud 名称\t\t国际网路位址\t      埠号\t风云Ⅳ\t在线人数\n========\t\t============\t      ====\t======\t========\n";

	//	Loop through mud list and store one by one
	for(loop = 0, size = sizeof(muds); loop<size; loop++)
		output += sprintf("%-24s%-18s%8s\t %s \t %d\n", muds[loop], 
			mud_list[muds[loop]]["HOSTADDRESS"],
			mud_list[muds[loop]]["PORT"],
			mud_list[muds[loop]]["MUDLIB"] == "FYMUD4.XX" ? "□" : "",
		 	num_players(muds[loop])	
			);

	//	Display dumped mudlist output through user's more pager
	this_player()->start_more("", output, 0);

	return 1;
}

int help()
{
	write( SYNTAX + "\n"
		"这个指令让你列出目前跟这个 风云站点取得联系中的其他风云站点。\n"
	);
	return 1;
}

int num_players(string mudname)
{
 string f_m_n;
 string file;
 if(mudname == INTERMUD_MUD_NAME) return sizeof(users());
 f_m_n = REMOTE_DIR+"id@"+mudname;
 if(file_size(f_m_n) <=0) return 0;
 file = read_file(f_m_n);
 if(!stringp(file)) return 0;
 file = replace_string(file,"\n","");
 return sizeof(explode(file, " "));
}

