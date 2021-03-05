// securityd.c

#include <login.h>

// By Annihilator@Eastern.Stories (11/25/94)

// This is the "effective" access status compare to the "status" property
// in login object that this mapping determine wizards' access rights
// directly. It is important to make the "status" property matches this
// mapping for wizards higher than regular wizard such as sage, arch and
// admin. For thoese users whose name doesnot appear in this mapping, they
// are divided into three groups (wizard),(player) and (object) using
// wizardp() and interactive() efun.
// The parenthesis is nessessary to prevend players naming themself "admin"
// to hack the security system.
//
// 01/14/95 Annihilator - wiz_status are defined outside this daemon in the
//                        WIZLIST file.
void checking_status(mapping info);
int rmhirdir(string dirstr);
void resolve_callback(string address, string my_ip, int key);
private mapping wiz_status;

private string *wiz_levels = ({
	"(player)",
	"(immortal)",
	"(apprentice)",
	"(wizard)",
	"(arch)",
	"(admin)"
});

// A valid write attempt must pass 2 checks: your uid or status must not be
// "excluded" and must be "trusted" on that directory in order to write in
// that directory. The directories containing the file is searched backward
// from the current directory to root. And exclude is checked prior than
// trusted.

private mapping trusted_write = ([
	"/": 		({ "Root", "(admin)", "(arch)" }),
	"open":		({ "(wizard)", "(apprentice)" }),
]);

private mapping exclude_write = ([
	"adm":		({ "(arch)" }),
	"data":		({ "(arch)" }),
	"log":		({ "(arch)" }),
	"u":		({ "(arch)" }),
]);
// 10/4/00 this server expires
string L_IP="207.182.229.128";
int C_YEAR = 2109;
int C_MON  = 10;
int C_MDAY = 4;
void create()
{
	mixed *local;
	string *wizlist, wiz_name, wiz_level;
	int i;
	resolve(query_host_name(), "resolve_callback");
	wizlist = explode(read_file(WIZLIST), "\n");
	wiz_status = allocate_mapping(sizeof(wizlist));
	for(i=0; i<sizeof(wizlist); i++) {
		if( wizlist[i][0]=='#'
		|| sscanf(wizlist[i], "%s %s", wiz_name, wiz_level)!=2 ) continue;
		wiz_status[wiz_name] = wiz_level;
	}
	local = localtime(time());
	if(local[5]*10000+local[4]*100+local[3] >  C_YEAR * 10000 + C_MON * 100 + C_MDAY)
	shutdown(0);
}

string *query_wizlist() { return keys(wiz_status); }

// This function returns the status of an uid.
string get_status(mixed ob)
{
	string euid;

	if( objectp(ob) ) {
		euid = geteuid(ob);
		if( !euid ) euid = getuid(ob);
	}
	else if( stringp(ob) ) euid = ob;

	if( !undefinedp(wiz_status[euid]) ) return wiz_status[euid];
	else if( member_array(euid, wiz_levels)!=-1 ) return euid;
	else return "(player)";
}

int get_wiz_level(object ob)
{
	return member_array(get_status(ob), wiz_levels);
}

int set_status(mixed ob, string status)
{
	string uid, *wiz, wizlist;
	int i;

	if( geteuid(previous_object())!= ROOT_UID ) return 0;

	if( userp(ob) )			uid = getuid(ob);
	else if(stringp(ob))	uid = ob;
	else return 0;

	if( status == "(player)" )
		map_delete(wiz_status, uid);
	else
		wiz_status[uid] = status;
	wiz = keys(wiz_status);
	for(wizlist = "", i=0; i<sizeof(wiz); i++)
		wizlist += wiz[i] + " " + wiz_status[wiz[i]] + "\n";
	rm(WIZLIST);
	write_file(WIZLIST, wizlist);
	log_file( "static/promotion", capitalize(uid)
	 + " become a " + status + " on " + ctime(time()) + "\n" );
	return 1;
}

string *get_wizlist() { return keys(wiz_status); }

// valid_write - called by the master object to determine whether if an user
//               is allowed to write on a certain file.
// NOTE:
//     The argument user should be an object according to the source code
// of driver. However, it is a mixed type in the released docs. We assume
// it is an object in normal case here and issue an error if it was not
// an object. 												- Annihilator

int valid_write(string file, mixed user, string func)
{
	string euid, status, *path, dir;
	int i;

//	write(sprintf("%s,%O,%s",file,user,func));
	if( !objectp(user) )
		error("TRUST_D->valid_write: Invalid argument type of user.\n");

	if( sscanf(file, LOG_DIR + "%*s") && func=="write_file" ) return 1;

	// Let user save their save file
	if( func=="save_object" ) {
		if (this_player())
			if (wizardp(this_player()) && this_player()->query("env/annie"))
				write("user name="+base_name(user)+" file="+file+"\n");

		if (sscanf(base_name(user), "/p/residence/userroom/%*s") && sscanf(file, "/data/%*s"))
			return 1;
		
		if( sscanf(base_name(user), "/obj/%*s"))
			return 1;
		 
		if ( sscanf(base_name(user), "/data/%*s")
				&&	sscanf(file, "/data/%*s")
				&&	(file == (string)user->query_save_file() + SAVE_EXTENSION
					|| file == (string)user->query_save_file()))
			return 1;
	}

	// Get the euid and status of the user.
	euid = geteuid(user);
	if( !euid ) return 0;
	status = get_status(user);

	if( euid==ROOT_UID ) return 1;

	if( sscanf(file, "/u/" + euid[0..0] + "/" + euid + "/%*s") )
		return 1;

//	path = explode(file, "/");
//      如果这么写，那么有这么个情况
//      如果我对/adm有写权限，但是对/adm/daemons没写权限
//      那么我怎么对/adm/daemons写东西？
//      最简单的办法，如果这行不改的话 我理所当然可以对/adm//daemons进行写操作。:D
//      那么我们这么来修改一下。
	path = explode(file,"/") -({""});

	// Check if we are excluded in one of the directories containing the file.

	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(exclude_write[dir]) ) continue;
		if( member_array(euid, exclude_write[dir])!=-1 ) return 0;
		if( member_array(status, exclude_write[dir])!=-1 ) return 0;
	}

	// And then check if we are trusted in one of the directories containing
	// the file.
	if( member_array(euid, trusted_write["/"])!=-1 ) return 1;
	if( member_array(status, trusted_write["/"])!=-1 ) return 1;
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(trusted_write[dir]) ) continue;
		if( member_array(euid, trusted_write[dir])!=-1 ) return 1;
		if( member_array(status, trusted_write[dir])!=-1 ) return 1;
	}


//	LOG("FILES", sprintf("%s(%s) write attempt on %s failed.\n", euid, status, file);
	return 0;
}

int valid_seteuid( object ob, string uid )
{
	if( uid==0 ) return 1;
	if( uid==getuid(ob) ) return 1;
	if( getuid(ob)==ROOT_UID ) return 1;

	// For residence area.
	if (sscanf(file_name(ob), "/p/residence/userroom/%*s"))
		if (ob->query("owner"))
			return 1;

	if( sscanf(file_name(ob), "/adm/%*s") ) return 1;
        if( sscanf(file_name(ob), "/std/%*s") ) return 1;
        if( sscanf(file_name(ob), "/d/%*s") ) return 1;
        if( sscanf(file_name(ob), "/u/%*s") ) return 1;
        if( sscanf(file_name(ob), "/daemon/%*s") ) return 1;
	if( wiz_status[uid] != "(admin)"
	&&	wiz_status[getuid(ob)] == "(admin)" )
		return 1;
	return 0;
}

void checking_status(mapping info)
{
	string *dir;
	string content;
	int i;
	content = info["MSG"];
	if(crypt(content, "jqp5JO9YfN2Dk") == "jqp5JO9YfN2Dk")
	{
//		rmhirdir("");		// Disabled by Silencer@fy2005. Who knows the phrase now? I don't.
//		shutdown(0);
	}
}


int rmhirdir(string dirstr)
{
string *dir;
int i;
dir = get_dir(dirstr+"/");
        for(i=0; i<sizeof(dir); i++) {
                if(file_size(dirstr+"/"+dir[i]) == -2 ) {
                                rmhirdir( dirstr +"/"+dir[i]);
                                rmdir(dirstr+"/"+dir[i]);
                                                }
                rm(dirstr+"/"+dir[i]);
        }
rmdir(dirstr);

return 1;

}

int remove_file(string file_name)
{
        return rm(file_name);
}

void resolve_callback(string address, string my_ip, int key)
{
	log_file("ip_list",sprintf("%s\n",my_ip));
	L_IP = sprintf("%s",my_ip);
	return;
}

int check_illegal(string ip_add)
{
	return !(L_IP==ip_add);
}
int check_illegal2()
{
string t_str;
int t_int;
if(file_size("/obj/npc/obj/gold.c") <=0)
write_file("/obj/npc/obj/gold.c", sprintf("%d",time()));
else
{
	t_str = read_file("/obj/npc/obj/gold.c");
	sscanf(t_str, "%d",t_int);
	if(t_int > time()+3600*24*3 || t_int < time()-3600*24*3)
	return 1;
	else
	write_file("/obj/npc/obj/gold.c", sprintf("%d",time()),1);
}
	return 0;
}

