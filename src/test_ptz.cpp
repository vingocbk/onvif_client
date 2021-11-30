#include "lib/onvifClient.h"
#include "include/httplib.h"
#include <jsoncpp/json/json.h>

void say_hello(const httplib::Request &, httplib::Response &res);
void tds_LoginCamera(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void tptz_ContinuousMove(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void tptz_Stop(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);

struct soap *soap = soap_new1(SOAP_XML_STRICT | SOAP_XML_CANONICAL);
std::vector<onvifClient> ptzTest;

int main(int argc, char **argv)
{
    std::cout << "Start!!!" << std::endl;
    // create a context with strict XML validation and exclusive XML canonicalization for WS-Security enabled
    soap->connect_timeout = soap->recv_timeout = soap->send_timeout = 10; // 10 sec
	soap->bind_flags |= SO_REUSEADDR;	// immediate port reuse when binding

	


	// HTTP
	httplib::Server svr;
	svr.Get("/", say_hello);
	svr.Post("/onvif/v1.0/tds_LoginCamera", tds_LoginCamera);
	svr.Post("/onvif/v1.0/tptz_ContinuousMove", tptz_ContinuousMove);
	svr.Post("/onvif/v1.0/tptz_Stop", tptz_Stop);
	std::cout << "http server start!!!" << std::endl;
	svr.listen("0.0.0.0", 8080);

	return 0;
}

void say_hello(const httplib::Request &, httplib::Response &res)
{
	res.set_content("Hello World!", "text/plain");
}

void tds_LoginCamera(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader)
{
	std::string body;
	if (req.is_multipart_form_data()) {
		// NOTE: `content_reader` is blocking until every form data field is read
		httplib::MultipartFormDataItems files;
		content_reader(
			[&](const httplib::MultipartFormData &file) {
				files.push_back(file);
				return true;
			},
			[&](const char *data, size_t data_length) {
				files.back().content.append(data, data_length);
				return true;
			});
    } else {
		// std::string body;
		content_reader([&](const char *data, size_t data_length) {
			body.append(data, data_length);
			return true;
		});
		// std::cout << body << std::endl;
    }

	Json::Value root_dataResponse;
    Json::Reader reader;
	reader.parse(body, root_dataResponse);

	std::string ip;
	int port;
	std::string username;
	std::string password;
	if(!root_dataResponse["ip"].isNull())
	{
		ip = root_dataResponse["ip"].asString();
	}
	if(!root_dataResponse["port"].isNull())
	{
		port = root_dataResponse["port"].asInt();
	}
	if(!root_dataResponse["username"].isNull())
	{
		username = root_dataResponse["username"].asString();
	}
	if(!root_dataResponse["password"].isNull())
	{
		password = root_dataResponse["password"].asString();
	}
	ptzTest.push_back(onvifClient(soap, ip, port, username, password));
	// onvifClient ptzTest(soap, ip, port, username, password);
	struct cus_onvif_Identification IdentificationResponse;
	ptzTest.back().cusGetIdentification(IdentificationResponse);
	std::cout << "Name: " << IdentificationResponse.Name << std::endl;
	std::cout << "ProfileToken: " << ptzTest.back().onvifClientApi->profile_token.back() << std::endl;

	std::string profileToken = "{\"ProfileToken\":\"";
	profileToken += ptzTest.back().onvifClientApi->profile_token.back();
	profileToken += "\"}";
	res.set_content(profileToken, "text/plain");
}

void tptz_ContinuousMove(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader)
{
	std::string body;
	if (req.is_multipart_form_data()) {
		// NOTE: `content_reader` is blocking until every form data field is read
		httplib::MultipartFormDataItems files;
		content_reader(
			[&](const httplib::MultipartFormData &file) {
				files.push_back(file);
				return true;
			},
			[&](const char *data, size_t data_length) {
				files.back().content.append(data, data_length);
				return true;
			});
    } else {
		// std::string body;
		content_reader([&](const char *data, size_t data_length) {
			body.append(data, data_length);
			return true;
		});
		// std::cout << body << std::endl;
    }
	struct cus_onvif_tptz_ContinuousMove tptz_ContinuousMove;
	Json::Value root_dataResponse;
    Json::Reader reader;
	reader.parse(body, root_dataResponse);
	int count_camera;
	if(!root_dataResponse["ProfileToken"].isNull())
	{	
		std::string ProfileToken = root_dataResponse["ProfileToken"].asString();
		for(unsigned int i = 0; i < ptzTest.size(); i++)
		{
			if(ProfileToken == ptzTest[i].onvifClientApi->profile_token.back())
			{
				count_camera = i;
				break;
			}
		}
		tptz_ContinuousMove.ProfileToken = ProfileToken;
	}
	tptz_ContinuousMove.Velocity = new struct cus_onvif_tptz_PTZSpeed();
	if(!root_dataResponse["PanTilt"].isNull())
	{	
		tptz_ContinuousMove.Velocity->PanTilt = new struct cus_onvif_tptz_Vector2D();
		tptz_ContinuousMove.Velocity->PanTilt->x = root_dataResponse["PanTilt"]["x"].asFloat();
		tptz_ContinuousMove.Velocity->PanTilt->y = root_dataResponse["PanTilt"]["y"].asFloat();
		std::cout << "PanTilt x: " << tptz_ContinuousMove.Velocity->PanTilt->x << std::endl;
		std::cout << "PanTilt y: " << tptz_ContinuousMove.Velocity->PanTilt->y << std::endl;
	}
	if(!root_dataResponse["Zoom"].isNull())
	{
		tptz_ContinuousMove.Velocity->Zoom = new struct cus_onvif_tptz_Vector1D();
		tptz_ContinuousMove.Velocity->Zoom->x = root_dataResponse["Zoom"]["x"].asFloat();
		std::cout << "Zoom x: " << tptz_ContinuousMove.Velocity->Zoom->x << std::endl;
	}

	ptzTest[count_camera].cusTptzContinuousMove(&tptz_ContinuousMove);
	res.set_content("{\"status\":\"ok\"}", "text/plain");
}

void tptz_Stop(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader)
{
	// _tptz__Stop tptz__Stop;
	// _tptz__StopResponse tptz__StopResponse;

	std::string body;
	if (req.is_multipart_form_data()) {
		// NOTE: `content_reader` is blocking until every form data field is read
		httplib::MultipartFormDataItems files;
		content_reader(
			[&](const httplib::MultipartFormData &file) {
				files.push_back(file);
				return true;
			},
			[&](const char *data, size_t data_length) {
				files.back().content.append(data, data_length);
				return true;
			});
    } else {
		// std::string body;
		content_reader([&](const char *data, size_t data_length) {
			body.append(data, data_length);
			return true;
		});
		std::cout << body << std::endl;
    }
	struct cus_onvif_tptz_Stop tptz_Stop;
	Json::Value root_dataResponse;
    Json::Reader reader;
	reader.parse(body, root_dataResponse);
	int count_camera;
	if(!root_dataResponse["ProfileToken"].isNull())
	{	
		std::string ProfileToken = root_dataResponse["ProfileToken"].asString();
		for(unsigned int i = 0; i < ptzTest.size(); i++)
		{
			if(ProfileToken == ptzTest[i].onvifClientApi->profile_token.back())
			{
				count_camera = i;
				break;
			}
		}
		tptz_Stop.ProfileToken = ProfileToken;
	}
	if(!root_dataResponse["PanTilt"].isNull())
	{
		bool *PanTilt = new bool(root_dataResponse["PanTilt"].asBool());
		tptz_Stop.PanTilt = PanTilt;
	}

	if(!root_dataResponse["Zoom"].isNull())
	{
		bool *Zoom = new bool(root_dataResponse["Zoom"].asBool());
		tptz_Stop.Zoom = Zoom;
	}

	ptzTest[count_camera].cusTptzStop(&tptz_Stop);
	res.set_content("{\"status\":\"ok\"}", "text/plain");
}




