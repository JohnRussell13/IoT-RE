import { makeStyles } from '@material-ui/core/styles';

export default makeStyles(() => ({
  appBar: {
    borderRadius: 15,
    margin: '30px 0 60px 0',
    display: 'flex',
    flexDirection: 'row',
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: "#111111",
  },
  heading: {
    paddingTop: '15px',
    color: '#42ffe7',
  },
  image: {
    marginLeft: '15px',
  },
}));